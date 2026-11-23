#include "easyfind.hpp"

int main()
{
	std::vector<int> b;
	std::list<int> a;
	b.resize(10);
	for (int i = 0; i < 10; i++)
	{
		b[i] = i * 3;
		a.push_back(i);
	}
	std:: cout << *easyfind(b, 9) << " is positioned at " << std::distance(b.begin(), easyfind(b, 9)) << std::endl;
	std:: cout << *easyfind(a, 9) << " is positioned at " << std::distance(a.begin(), easyfind(a, 9)) << std::endl;
}