'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-03 14:23:57
LastEditors: lxp
LastEditTime: 2021-07-05 23:48:28
'''
from c_1_perceptron import Perceptron_numpy, Perceptron_torch
from c_2_knn import KNN_numpy, KNN, Knn_sk
from c_3_naive_bayes import Native_Bayes
from c_5_logist_reg import LogisticRegression_numpy
from sklearn.linear_model import LogisticRegression
# sklearn
from sklearn.linear_model import Perceptron
from sklearn.neighbors import KNeighborsClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.tree import DecisionTreeClassifier
from sklearn.svm import LinearSVC
from sklearn.ensemble import AdaBoostClassifier
# data process
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
    n_samples=2000,
    n_features=10,
)
X_train, X_test, y_train, y_test = train_test_split(features,
                                                    labels,
                                                    test_size=0.2,
                                                    random_state=42)

# TODO: get the model
model_1 = Perceptron_numpy(verbose=False)
model_2 = Perceptron_torch(verbose=False)
sk_percetion = Perceptron()
knn_ = KNN_numpy()
knn_sk = KNeighborsClassifier()
# knn_tree = KNN()   # 有疑问
#native_Bayes = Native_Bayes()  # 有疑问
sk_native_Bayes = GaussianNB()
sk_dt_tree = DecisionTreeClassifier()
lg_model = LogisticRegression_numpy()
sk_lg_model = LogisticRegression()
sk_svm = LinearSVC()
sk_AdaBoost = AdaBoostClassifier()

# TODO: train the model
train_and_eval(model_1, 'np_percetion')
train_and_eval(model_2, 'torch_percetion')
train_and_eval(sk_percetion, "sk_percetion")
train_and_eval(knn_, "knn")
train_and_eval(knn_sk, "sk_knn")
#train_and_eval(knn_tree, "knn_tree")
train_and_eval(sk_native_Bayes, "sk_Native_Bayes")
train_and_eval(sk_dt_tree, "sk_DecisionTreeClassifier")
train_and_eval(lg_model, "LogisticRegression_numpy")
train_and_eval(sk_lg_model, "sk_lg_model")
train_and_eval(sk_svm, "sk_svm")
train_and_eval(sk_AdaBoost, "sk_AdaBoost")