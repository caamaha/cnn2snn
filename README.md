# 转换cnn为snn

## 准备
　　编译支持matlab的caffe，创建一个soft link到编译后的caffe目录。
``` bash
cd cnn2snn
ln -s /path/to/your/caffe `pwd`/caffe
```

　　每次打开matlab前source config.sh。

## lenet

``` bash
cd lenet
#获取mnist数据集
./mnist/get_mnist.sh
#生成caffe训练用的数据格式
./caffe/create_mnist.sh
#开始训练lenet
./caffe/train_lenet.sh
```

　　要注意caffe训练使用的是lenet_train_test.prototxt模型文件，而matlab所使用的是lenet_deploy.protxt模型文件。训练完成后，打开matlab，lenet_demo.m包含了一个使用caffe的matlab接口运行lenet的例子。
