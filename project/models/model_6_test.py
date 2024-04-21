import torch
import pandas as pd
from torch.utils.data import TensorDataset, DataLoader
from sklearn.model_selection import train_test_split
import csv
import numpy
import sklearn

IN_FEATURES = 1740

'''输入数据集'''
csv_file_path_X = '/Users/linto/Codes/project/output_X.csv'
data_X = pd.read_csv(csv_file_path_X)
# data_X = data_X.astype()

data_X = data_X.apply(pd.to_numeric, errors='coerce')  # 将无法转换为数值的值设置为NaN
data_X = data_X.fillna(0)  # 将NaN值设置为0

csv_file_path_y = '/Users/linto/Codes/project/output_y.csv'
data_y = pd.read_csv(csv_file_path_y)

data_y = data_y.apply(pd.to_numeric, errors='coerce')  # 将无法转换为数值的值设置为NaN
data_y = data_y.fillna(0)  # 将NaN值设置为0

'''查看输出'''
X = torch.FloatTensor(data_X.values)
y = torch.FloatTensor(data_y.values)
# print(X)
# print(y)

# 划分训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(data_X, data_y, test_size=0.2, random_state=42)
# 转换为PyTorch张量
X_train = torch.tensor(X_train.values, dtype=torch.float)
y_train = torch.tensor(y_train.values, dtype=torch.float)
X_test = torch.tensor(X_test.values, dtype=torch.float)
y_test = torch.tensor(y_test.values, dtype=torch.float)

# 对输入张量归一化
X_train = (X_train - X_train.mean()) / X_train.std()
X_test = (X_test - X_test.mean()) / X_test.std()

import torch
from torch import nn, optim

# 定义模型
model = nn.Sequential(
    nn.Linear(IN_FEATURES, 128),  # 输入层
    nn.ReLU(),  # 激活函数
    nn.Linear(128, 32),  
    nn.ReLU(),
    nn.Linear(32, 1)  # 输出层
)

# 定义损失函数和优化器
loss_fn = nn.MSELoss()
optimizer = optim.Adam(model.parameters())

# 训练
ITERATION = 100000
for epoch in range(ITERATION):
    if (epoch + 1) % 1000 == 0:  # 每1000次迭代打印一次
        print('Epoch: {:.2f}%'.format((epoch + 1)/ITERATION * 100))

    # 前向传播
    y_pred = model(X_test)

    # 计算损失
    loss = loss_fn(y_pred, y_test)

    # 反向传播
    loss.backward()

    # 更新权重
    optimizer.step()

    # 清零梯度
    optimizer.zero_grad()

y_test_pred = model(X_test)
# print((torch.nn.functional.mse_loss(y_test_pred, y_test) / (IN_FEATURES * 0.2)))
print('y_test_pred:', y_test_pred)
print('y_test:', y_test)

# y_test_pred_numpy = y_test_pred.detach().numpy()
# numpy.savetxt('/Users/linto/Codes/project/output_y_test_pred.csv', y_test_pred_numpy, delimiter=',')

def measure_accuracy(y_pred, y):
    mean = 0
    for i in range(torch.numel(y)):
        mean += abs(y_pred[i] - y[i])
    return mean / torch.numel(y)

print('accuracy:', measure_accuracy(y_test_pred, y_test).item())
print('MSE', sklearn.metrics.mean_squared_error(y_test_pred.detach().numpy(), y_test.detach().numpy()))
print('RMAE', numpy.sqrt(sklearn.metrics.mean_squared_error(y_test_pred.detach().numpy(), y_test.detach().numpy())))
print('MAE', sklearn.metrics.mean_absolute_error(y_test_pred.detach().numpy(), y_test.detach().numpy()))
print('R2', sklearn.metrics.r2_score(y_test_pred.detach().numpy(), y_test.detach().numpy()))
print('MAPE', sklearn.metrics.mean_absolute_percentage_error(y_test_pred.detach().numpy(), y_test.detach().numpy()))