/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-25 19:18:38
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-25 19:27:30
 */
#include <iostream>
#include <string>
using namespace std;

struct Person 
{
    std::string const& getName()    const { return name; }
    std::string const& getAddress() const { return address; }
    
    std::string name;
    std::string address;
};

istream &read(istream &is, Person &person)
{
    return is >> person.name >> person.address;
}

ostream &print(ostream &os, const Person &person)
{
    return os << person.name << " " << person.address;
}