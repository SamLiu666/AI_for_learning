/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-11 10:04:20
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-11 10:31:22
 */
#include <iostream>
using namespace std;
struct student {
    int id;
    student *next;
};

student *create();              // 创建链表
void studentPrint(student *p);  // 遍历链表
student *dele(student *head, int n); // 删除为n的节点
student *insert(student *head, int n); // 插入为n的节点

int main() {
    student *pointer = create();
    studentPrint(pointer);
    dele(pointer, 3);
    studentPrint(pointer);
    insert(pointer, 3);
    studentPrint(pointer);
    return 0;
}

student *create() {
    student *head, *temp; int num, n=0;
    head = new student;
    temp = head;
    cout << "create linkNode List(-1 end): \n";
    cin >> num;
    while (num != -1) {
        n++;
        temp->id = num;
        temp->next = new student;
        temp = temp->next;
        cin >> num;
    }
    if (n == 0) {
        head = NULL;
    } else {
        temp->next=NULL;
    }
    return head;
}

void studentPrint(student *p) {
    cout << "print linknode list: \n";
    while (p->next != NULL) {
        cout << p->id << endl;
        p = p->next;
    }
}

student *dele(student *head, int n) {
    cout << "delete " << n << " from linknode. \n";
    if (head == NULL) return head; // head 为空

    student *temp, *follow;
    temp = head;
    if(head->id == n) {
        // 删除头节点并释放内存
        head->next = temp->next;
        delete temp;
        return head;
    }

    while (temp != NULL && temp->id != n) {
        // 寻找要删除的目标
        follow = temp; temp = temp->next;
    }
    if (temp == NULL) cout << "Not Found \n";  //未找到
    else {
        follow->next = temp->next;
        delete temp;
    }
    return head;
}

student *insert(student *head, int n) {
    cout << "insert " << n << " into linknode. \n";
    student *temp, *follow, *unit;
    temp = head; 
    unit = new student; unit->id = n; unit->next = NULL;
    
    if (head == NULL) {
        head = unit;
        return head; // head 为空
    }

    while (temp->next != NULL && temp->id < n) {
        // 插入到比n小的节点前面
        follow = temp; temp = temp->next;
    }
    if (temp == head) {
        // 头节点
        unit->next = temp; head=unit;
    } else {
        if (temp->next == NULL) temp->next = unit; // temp最后一个结点
        else {
            follow->next = unit;
            unit->next = temp; 
        }
    }
    return head;
}
