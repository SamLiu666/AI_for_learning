/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-28 13:35:36
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-28 13:48:17
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void replace(string& s, const string& oldVal, const string& newVal) {
    auto cur = s.begin();
    while (cur != s.end() - oldVal.size()) {
        if (oldVal == string(cur, cur+oldVal.size())) {
            cur = s.erase(cur, cur+oldVal.size());
            cur = s.insert(cur, newVal.begin(), newVal.end());
            cur += newVal.size();
        } else {
            ++cur;
        }
    }
}

void replace_2(string& s, const string& oldVal, const string& newVal)
{
	for (size_t pos = 0; pos <= s.size() - oldVal.size(); /* */)
	{
		if (s[pos] == oldVal[0] && s.substr(pos, oldVal.size()) == oldVal)
		{
			s.replace(pos, oldVal.size(), newVal);
			pos += newVal.size();
		}
		else
		{
			++pos;
		}
	}
	
}

string add_pre_and_suffix(string name, string const& pre, string const& su)
{
	name.insert(name.begin(), pre.cbegin(), pre.cend());
	return name.append(su);
}

string add_pre_and_suffix_2(std::string name, std::string const& pre, std::string const& su)
{
	name.insert(0, pre);
	name.insert(name.size(), su);
	return name;
}
int sum_of_int(const vector<string>& v)
{
	int sum = 0;
	for (auto i : v)
	{
		sum += stoi(i);
	}
	return sum;
}

float sum_of_float(const vector<string>& v)
{
	float sum = 0;
	for (auto i : v)
	{
		sum += stof(i);
	}
	return sum;
}
int main()
{
	// string s("To drive straight thru is a foolish, tho courageous act.");
	// cout << s << endl;
    // replace(s,"tho","though");
	// replace(s, "thru", "through");

	// cout << s << endl;

	// string name("Huang");
	// cout << add_pre_and_suffix(name, "Mr.", " Jr.") << endl;

	string numbers("0123456789");
	string s("ab2c3d7R4E6");

	cout << "numeric characters: ";
	for (int pos = 0; (pos = s.find_first_of(numbers, pos)) != string::npos; ++pos)
	{
		cout << s[pos] << " ";
	}

	cout << "\nalphabetic characters: ";
	for (int pos = 0; (pos = s.find_first_not_of(numbers, pos)) != string::npos; ++pos)
	{
		cout << s[pos] << " ";
	}

    return 0;
}