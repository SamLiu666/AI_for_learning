/*
 * @Description:
5
1 2 2 2 3 1 2 3 1 4
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-12 20:05:55
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-12 20:24:57
 */
#include <iostream>
using namespace std;
struct point {
    int x;
    int y;
};

int main() {
    int n; cin >> n;
    point points[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // 找出极大值点
    point maxPoints[n];
    int k = 0; // 极大值点索引
    for (int i = 0; i < n; i++) {
        bool maxFlax = true;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                // 同一个点跳过
                continue;
            }
            if (points[i].x <= points[j].x && points[i].y <= points[j].y) {
                // 不是极大值点
                maxFlax = false;
            }
        }
        if (maxFlax) {
            maxPoints[k++] = points[i];
        }
    }

    // 冒泡排序 从大到小输出极大值点
    for (int i=0; i < k - 1; i++) {
        for (int j=0; j < k - i - 1; j++) {
            if (maxPoints[j].x > maxPoints[j + 1].x) {
                point temp = maxPoints[j];
                maxPoints[j] = maxPoints[j + 1];
                maxPoints[j + 1] = temp;
            }
        }
    }

    // 打印结果
    for (int i = 0; i < k; i++) {
        cout << '(' << points[i].x << "," << points[i].y << ')';
        if (i != k-1) {
            cout << ',';
        }
    }

    return 0;
}