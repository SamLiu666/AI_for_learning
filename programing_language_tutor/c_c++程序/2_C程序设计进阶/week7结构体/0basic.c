/*
 * @Description: 结构体 -- 链表
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-11 09:33:56
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-11 10:06:44
 */
#include <iostream>
using namespace std;
sLinkNode *creat();
struct student {
    int id_num;
    char name[10];
};

struct sLinkNode {
    int id;
    sLinkNode *next;
};


int main() {
    student mike = {123, {'m', 'i', 'k', 'e', '\0'}};
    cout << mike.id_num << " " << mike.name << endl;

    student *one = &mike;  // 更改了指向地址的内容
    (*one).id_num += 20200000;
    cout << (*one).id_num << " " << one->name << endl;
    cout << mike.id_num << " " << mike.name << endl;

    // *链表操作
    creat();
    return 0;
}

sLinkNode *creat() {
    sLinkNode *head, *temp; int num, n=0;
    head = new sLinkNode;
    temp = head;
    cout << "Input student id: ";
    cin >> num;
    while (num != -1) {
        n++;
        temp->id = num;
        temp->next = new sLinkNode;
        temp = temp->next;
        cin >> num;
    }
    if (n == 0) {
        head = NULL;
    } else {
        temp->next=NULL;
    }
    sLinkNode *temp_2 = head;
    while (temp_2) {
        cout << temp_2->id << " " << temp_2->next << endl;
        temp = temp_2->next;
    }
    return head;
}
