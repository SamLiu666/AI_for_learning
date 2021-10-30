/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-29 13:44:25
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-29 13:50:54
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void elimdups(std::vector<std::string> &vs)
{
	std::sort(vs.begin(), vs.end());
	auto new_end = std::unique(vs.begin(), vs.end());
	vs.erase(new_end, vs.end());
}

void biggies(std::vector<std::string> &vs, std::size_t sz)
{

	elimdups(vs);

	std::stable_sort(vs.begin(), vs.end(), 
		[](string const& lhs, string const& rhs) {
		return lhs.size() < rhs.size(); }
	);

	auto wc = std::find_if(vs.begin(), vs.end(), 
		[sz](string const& s) { return s.size() >= sz; }
	);

	std::for_each(wc, vs.end(),
		[](const string &s) {
		std::cout << s << " "; }
	);
}

void biggies_stable_partition(std::vector<std::string> &vs, std::size_t sz)
{
	elimdups(vs);

	auto pivot = stable_partition(vs.begin(), vs.end(), [sz](const std::string& s)
	{
		return s.size() >= sz;
	});

	for (auto it = vs.cbegin(); it != pivot; ++it)
		std::cout << *it << " ";
}

int main() {
    auto f1 = [](int i, int j) { return i + j;}; // lambda 表达式

    int x = 10;
    auto f2 = [x](int i) {i + x;};

	std::vector<std::string> v
	{
	"1234", "1234", "1234", "hi~", "alan", "alan", "cp"
};
	std::cout << "ex10.16: ";
	// biggies(v, 3);
    biggies_stable_partition(v, 4);
	std::cout << std::endl;

    return 0;
}