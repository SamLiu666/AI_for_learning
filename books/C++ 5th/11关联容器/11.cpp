/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-30 11:32:43
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-30 12:08:59
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Families
{
public:
	using Child = pair<string, string>;
	using Children = vector<Child>;
	using Data = map<string, Children>;

	void add(string const& last_name, string const& first_name, string birthday)
	{
		auto child = make_pair(first_name, birthday);
		_data[last_name].push_back(child);
	}

	void print() const
	{
		for (auto const& pair : _data)
		{
			cout << pair.first << ":\n";
			for (auto const& child : pair.second)
				cout << child.first << " " << child.second << endl;
			cout << endl;
		}
	}

private:
	Data _data;
};

void ex31() {
    multimap<string, string> authors{
		{ "alan", "DMA" },
		{ "pezy", "LeetCode" },
		{ "alan", "CLRS" },
		{ "wang", "FTP" },
		{ "pezy", "CP5" },
		{ "wang", "CPP-Concurrency" } };
    map<string, multiset<string>> order_authors;
	for (const auto &author : authors)
		order_authors[author.first].insert(author.second);

	for (const auto &author : order_authors)
	{
		std::cout << author.first << ": ";
		for (const auto &work : author.second)
			std::cout << work << " ";
		std::cout << std::endl;
	}

    string author = "pezy"; string work = "CP5";
    auto found = authors.find(author);
    auto count = authors.count(author);
	while (count)
	{
		if (found->second == work)
		{
			authors.erase(found);
			break;
		}
		++found;
		--count;
	}

	for (const auto &author : authors)
		std::cout << author.first << " " << author.second << std::endl;
    
}

int main() {
	// Families families;
	// auto msg = "Please enter last name, first name and birthday:\n";
	// for (string l, f, b; cout << msg, cin >> l >> f >> b; families.add(l, f, b));
	// families.print();

    ex31();
    return 0;
}