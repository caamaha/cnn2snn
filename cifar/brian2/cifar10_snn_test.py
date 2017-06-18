from multiprocessing import Process
from multiprocessing import Pool
import os
import threading
import scipy.io as sio
import time

process_num = 4
samples_num = 10000
samples_per_count = samples_num / process_num

def get_process(info):
    print info
    print 'Process ID:', os.getpid()
    print 'Parent process ID:', os.getppid()

def readfile(filename):
    tmp_right_num = 0
    tmp_total_num = 0    
    if os.path.exists(filename):
        if os.path.getsize(filename):
            result = sio.loadmat(filename)
            tmp_right_num = result['sample_right']
            tmp_total_num = result['sample_counts']
    return tmp_right_num, tmp_total_num

def func_timer():
    print 'summary:'
    global timer
    timer = threading.Timer(10, func_timer)
    timer.start()

    # read file
    sample_right = 0
    sample_counts = 0
    for i in range(process_num):
        filename = 'output/result_' + str(i * samples_per_count) + '.mat'
        tmp_right_num, tmp_total_num = readfile(filename)
        sample_right += tmp_right_num
        sample_counts += tmp_total_num
    if sample_counts > 0:
        print('%f %d %d' % (sample_right / sample_counts, sample_right, sample_counts))

def process_func(test_start, test_end):
    time.sleep(1)
    os.system('python cifar10_snn.py %d %d' % (test_start, test_end))

if __name__ == "__main__":
    print 'Parent process %s.' % os.getpid()
    timer = threading.Timer(1, func_timer)
    timer.start()
    
    p = Pool()
    for i in range(process_num):
        p.apply_async(process_func, args=(i*samples_per_count, (i+1)*samples_per_count))
    print 'Waiting for all subprocesses done...'
    p.close()
    p.join()
    print 'All subprocesses done.'
    timer.cancel()