/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-28 10:48:31
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-28 11:24:37
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main() {
    list<int> list_EX(5, 4);
    vector<int> vec(5, 5);

    vector<double> vecL(list_EX.begin(), list_EX.end());
    for (auto i:list_EX) cout << i;
    cout <<" list_EX done" << endl;

    vector<double> vecI(vec.begin(), vec.end());
    for(auto i:vecI) cout << i;
    cout << " vec done " << endl;

    for(auto i:vec) cout << i;
    cout << " vec2 done " << endl;

    list<const char*> exl{"Mooophy", "pezy", "Queeuqueg"};
    vector<string> ans;
    ans.assign(exl.cbegin(), exl.cend());
    for (const auto& ch : ans) std::cout << ch << std::endl;

    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{1, 2, 3, 4, 5};
    std::vector<int> vec3{1, 2, 3, 4};

    std::cout << std::boolalpha << (vec1 == vec2) << std::endl;
    std::cout << std::boolalpha << (vec1 == vec3) << std::endl;
    std::cout << std::boolalpha
              << (std::vector<int>(vec2.begin(), vec2.end()) == vec1)
              << std::endl;
    std::cout << std::boolalpha
              << (std::vector<int>(vec3.begin(), vec3.end()) == vec2)
              << std::endl;

    //deque<string> input;
    list<string> input;
    for (string str; cin >> str; input.emplace_back(str)) {;}
    for (auto str : input) { cout << str << endl;} 
    cout << endl;
    for (auto iter = input.cbegin(); iter != input.cend(); ++iter)
        cout << *iter << endl;

    list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int> odd, even;
    //for (auto i:l) (i%2 == 1? odd:even).emplace_back(i);
    for (auto i : l) (i & 0x1 ? odd : even).push_back(i);
    for (auto i : odd) cout << i << " ";
    cout << endl;
    for (auto i : even) cout << i << " ";
    cout << endl; 

    std::vector<int> v{1,2,3};
    std::cout << v.at(
        0); // terminating with uncaught exception of type std::out_of_range
    std::cout << v[0];       // Segmentation fault: 11
    std::cout << v.front();  // Segmentation fault: 11
    std::cout << *v.begin(); // Segmentation fault: 11
    
    return 0;

}