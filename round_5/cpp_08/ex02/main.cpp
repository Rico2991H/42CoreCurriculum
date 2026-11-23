#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<std::string> Ms;
	MutantStack<int, std::vector<int> > Ms2;
	Ms.push("Hello ");
	Ms.push("World ");
	Ms.push(", Have a good day\n");
	Ms2.push(1);
	Ms2.push(2);
	Ms2.push(3);

	for ( std::deque<std::string>::iterator start = Ms.begin(); start != Ms.end(); ++start)
		std::cout << *start << std::endl;

	for ( std::vector<int>::iterator start = Ms2.begin(); start != Ms2.end(); ++start)
		std::cout << *start << std::endl;
	
	for ( MutantStack<int, std::vector<int> >::iterator start = Ms2.begin(); start != Ms2.end(); ++start)
			std::cout << *start << std::endl;
}

/*int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0
}
int main()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::list<int> s(mstack);
	return 0;
}*/