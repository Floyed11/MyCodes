from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression, LogisticRegression
import numpy as np

import pandas as pd

data_url = "http://lib.stat.cmu.edu/datasets/boston"
raw_df = pd.read_csv(data_url, sep="\s+", skiprows=22, header=None)
data = np.hstack([raw_df.values[::2, :], raw_df.values[1::2, :2]])
target = raw_df.values[1::2, 2]

# -----------------------------Data load
# Training and testing split,
# 80% for training and 20% for testing

# boston = datasets.load_boston()
# (trainData_boston, testData_boston, trainLabels_boston, testLabels_boston) = train_test_split(
#     np.array(boston.data), boston.target, test_size=0.2, random_state=3407
# )

(trainData_boston, testData_boston, trainLabels_boston, testLabels_boston) = train_test_split(
    np.array(data), target, test_size=0.2, random_state=3407
)

# Training and testing split,
# 10% for training and 90% for testing
iris = datasets.load_iris()
(trainData_iris, testData_iris, trainLabels_iris, testLabels_iris) = train_test_split(
    np.array(iris.data), iris.target, test_size=0.9, random_state=3407
)
# Checking sizes of each data split
print("training data points of boston: {}".format(len(trainLabels_boston)))
print("testing data points of boston: {}".format(len(testLabels_boston)))

print("training data points of iris: {}".format(len(trainLabels_iris)))
print("testing data points of iris: {}".format(len(testLabels_iris)))
# -----------------------------Data load

# -----------------------------Train
### your code
linear_model = LinearRegression()
linear_model.fit(trainData_boston, trainLabels_boston)

logistic_model = LogisticRegression()
logistic_model.fit(trainData_iris, trainLabels_iris)
# -----------------------------Train

# -----------------------------Prediction result
from sklearn.metrics import mean_squared_error, r2_score, accuracy_score
# evaluate the model
mse_linear = 0
r2_linear = 0
acc_logistic = 0

## your code
pred_boston = linear_model.predict(testData_boston)
mse_linear = mean_squared_error(testLabels_boston, pred_boston)
r2_linear = r2_score(testLabels_boston, pred_boston)
acc_logistic = accuracy_score(testLabels_iris, logistic_model.predict(testData_iris))

print("Mean Squared Error of Linear Regression: ", mse_linear)
print("R Squared of Linear Regression: ", r2_linear)
print("Accuracy of Logistic Regression: ", acc_logistic)
# -----------------------------Prediction result