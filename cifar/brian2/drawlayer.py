import scipy.io as sio
import numpy as np
from sklearn import linear_model
import matplotlib.pyplot as plt  
from scipy import optimize  
import pylab
from scipy import stats

snn_result = sio.loadmat('output/snn_counts.mat')
snn_conv2 = snn_result['conv2']
snn_pool2 = snn_result['pool2']

cnn_result = sio.loadmat('../tf_snn/output/cifar10_cnn.mat')
cnn_conv2 = cnn_result['conv2'][0,:]
cnn_pool2 = cnn_result['pool2'][0,:]

X = cnn_pool2
Y = snn_pool2[0,:]
print X.shape
print Y.shape

slope, intercept, r_value, p_value, slope_std_error = stats.linregress(X, Y)

predict_y = intercept + slope * X
pred_error = Y - predict_y
degrees_of_freedom = len(X) - 2
residual_std_error = np.sqrt(np.sum(pred_error**2) / degrees_of_freedom)

# Plotting
pylab.plot(X, Y, 'o')
pylab.plot(X, predict_y, 'k-')
pylab.show()
