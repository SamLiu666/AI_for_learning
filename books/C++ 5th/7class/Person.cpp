/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-27 11:16:54
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-27 12:31:31
 */
#include <iostream>
#include <string>
using namespace std;

class Person {
    friend istream &read(istream& is, Person &person);
    friend ostream &print(ostream& os, Person &person);

public:
    Person() = default;
    Person(const string sname, const string saddr):name(sname), address(saddr) {}
    Person(istream &is) {read(is, *this); }

    string getName() const { return name; }
    string getAddress() const { return address; }

private:
    string name;
    string address;
};

istream &read(istream& is, Person &person) {
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream& os, Person &person) {
    os << person.name << " " << person.address;
    return os;
}