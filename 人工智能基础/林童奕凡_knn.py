from sklearn import datasets
from sklearn.model_selection import train_test_split
import numpy as np
from sklearn import neighbors

# -----------------------------Data load
# Training and testing split,
# 80% for training and 20% for testing
mnist = datasets.load_digits()
(trainData, testData, trainLabels, testLabels) = train_test_split(
    np.array(mnist.data), mnist.target, test_size=0.2, random_state=3407
)
# Checking sizes of each data split
print("training data points: {}".format(len(trainLabels)))
print("testing data points: {}".format(len(testLabels)))
# -----------------------------Data load

# -----------------------------Train for KNN
scores = []
Ks = []
for K in range(1, 11):
    Ks.append(K)
    knn = neighbors.KNeighborsClassifier(n_neighbors= K)
    knn.fit(trainData, trainLabels)
    score = knn.score(testData, testLabels)
    scores.append(score * 100)
### your code


# -----------------------------Train for KNN

# -----------------------------Prediction result
for K, score in zip(Ks, scores):
    print("K=%d, accuracy=%.2f%%" % (K, score))
# -----------------------------Prediction result