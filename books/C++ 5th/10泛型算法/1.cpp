/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-29 13:08:39
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-29 13:42:54
 */
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <numeric>
#include "C:\Users\lxp\Desktop\AI_for_learning\books\C++ 5th\7class\Sales_data.h"
using namespace std;

bool predicate(const std::string &s)
{
	return s.size() >= 5;
}

void predicateTest() {
	auto v = std::vector<std::string>{ "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
	auto pivot = std::partition(v.begin(), v.end(), predicate);

	for (auto it = v.cbegin(); it != pivot; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

inline bool compareIsbn(const Sales_data& a, const Sales_data& b) {
    return a.isbn().size() < b.isbn().size();
}

void testIsbnCompare() {
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
	std::vector<Sales_data> v{ d1, d2, d3, d4, d5 };

	std::sort(v.begin(), v.end(), compareIsbn);

	for (const auto &element : v)
		std::cout << element.isbn() << " ";
	std::cout << std::endl;
}

inline bool isShorter(string const& lhs, string const& rhs) {
    return lhs.size() < rhs.size();
}

void print(vector<string> &words, const string &name = "words: ") {
    cout << name;
    for (auto w:words) cout << w << " ";
    cout<< endl;
}

void elimDups(vector<string> &words) {
    print(words);
    sort(words.begin(), words.end());  // 字典序排序

    auto unqWord = unique(words.begin(), words.end());
    print(words, "after unique: ");

    words.erase(unqWord, words.end());
    print(words, "after erase: ");

    stable_sort(words.begin(), words.end(), isShorter);
    print(words, "after stable_sort: ");
}

int main() {
    cout << "predicateTest: " << endl;
    predicateTest();
    cout << endl;
    
    cout << "testIsbnCompare: " << endl;
    testIsbnCompare();
    cout << endl;
    vector<string> words = {"1234", "1234", "1234", "Hi", "alan", "wang"}; // {"the", "quick", "red", "fox", "red"};
    elimDups(words);

    vector<int> vec = {1,3,3,3,4};
    // int t;
    // while (cin >> t) {
    //     vec.emplace_back(t);
    // }
    int cnt = count(vec.cbegin(), vec.cend(), 3);
    cout << "3 in vec cnt: " << cnt << endl;
    cout << "accumulate vec: " << accumulate(vec.cbegin(), vec.cend(), 0) << endl;

    cout << "fill_N: ";
    fill_n(vec.begin(), vec.size(), 0);
    for (auto v : vec) cout << v << " ";
    cout << endl;

    // 读取string
    list<string> l1 = { "aa", "aaa", "aa", "cc" };
    cout << "aa in l1 cnt: " << count(l1.cbegin(), l1.cend(), "aa") << endl;
    return 0;
}