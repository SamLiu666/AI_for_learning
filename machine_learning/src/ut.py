'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-03 14:23:57
LastEditors: lxp
LastEditTime: 2021-07-04 22:47:57
'''
from c_1_perceptron import Perceptron_numpy, Perceptron_torch
from c_2_knn import KNN_numpy, KNN
from c_3_naive_bayes import Native_Bayes
from c_4_logist_reg import LogisticRegression_numpy
# sklearn
from sklearn.naive_bayes import GaussianNB
from sklearn.tree import DecisionTreeClassifier
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import time


# train
def train_and_eval(model, name=None):
    start = time.time()
    model.fit(X_train, y_train)
    # predict
    test_predict = model.predict(X_test)
    score = accuracy_score(y_test, test_predict)
    end = time.time()
    print("{} 's accruacy socre is {} cost time: {}".format(
        name, score, round(end - start, 4)))


features, labels = make_classification(
    n_samples=200,
    n_features=4,
)
X_train, X_test, y_train, y_test = train_test_split(features,
                                                    labels,
                                                    test_size=0.2,
                                                    random_state=42)

# TODO: get the model
model_1 = Perceptron_numpy(verbose=False)
model_2 = Perceptron_torch(verbose=False)
knn_ = KNN_numpy()
# knn_tree = KNN()   # 有疑问
#native_Bayes = Native_Bayes()  # 有疑问
native_Bayes = GaussianNB()
dt_tree = DecisionTreeClassifier()
lg_model = LogisticRegression_numpy()
# TODO: train the model
train_and_eval(model_1, 'per_np')
train_and_eval(model_2, 'per_torch')
train_and_eval(knn_, "knn")
#train_and_eval(knn_tree, "knn_tree")
train_and_eval(native_Bayes, "Native_Bayes")
train_and_eval(dt_tree, "DecisionTreeClassifier")
train_and_eval(lg_model, "LogisticRegression_numpy")