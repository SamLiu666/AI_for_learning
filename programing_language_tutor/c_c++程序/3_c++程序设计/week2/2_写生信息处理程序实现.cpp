/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-15 16:01:32
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-15 16:23:21
 */
#include <iostream>
using namespace std;
class Student {
    char name[100], id[100];
    int age, avg[4];

    public:
        void Init() {
            char f;
            cin.getline(name, 100, ',');
            cout << "name: " << name << endl;
            cin >> age >> f;
            cout << "age: " << age << endl;
            cin.getline(id, 100, ',');
            cout << "id: " << id << endl;
            cin >> avg[0] >> f >> avg[1] >> f >> avg[2] >> f >> avg[3];
        }

        void printInfo() {
            int score = 0;
            for (int i=0; i<4; i++) {
                score += avg[i];
            }
            score /= 4;
            cout << name << ',' << age << ',' << id << ',' << score << endl;
        }

};

int main() {
    Student s1;
    s1.Init();
    s1.printInfo();

    return 0;
}