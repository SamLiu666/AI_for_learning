/*
 * @Author: [lxp]
 * @Date: 2022-01-20 11:17:17
 * @LastEditors: [lxp]
 * @LastEditTime: 2022-01-20 11:35:37
 * @Description: 
 */
#include <iostream>

using namespace std;


class Subject
{
public:
    virtual ~Subject() {cout << "Subject delete" << endl;};

    virtual void request() = 0;  // 纯虚函数
    // ...  
};

class RealSubject : public Subject
{
public:
    void request() {cout << "RealSubject::request" << endl;}
    //....
};

class Proxy : public Subject
{
public:
    Proxy() {subject = new RealSubject();}
    ~Proxy() { delete subject;}
    void preRequest() {
        cout << "Proxy :: preRequest" << endl;
    }
    void afterRequest() {
        cout << "Proxy :: afterRequest" << endl;
    }
    void request() {
        this->preRequest();
        subject->request();
        this->afterRequest();
    }

private:
    Subject *subject;
};

int main() {
    Proxy *p = new Proxy();
    p->request();
    return 0;
}
