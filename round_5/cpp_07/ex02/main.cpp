#include "Array.hpp"

int main()
{
	Array<int> NumberAr(5);
	Array<std::string> StrAr(5);
	int *a = new int();
	StrAr[1] = "Hello ";
	NumberAr[3] = 2;
	std::cout << StrAr[1] << NumberAr[3] << " the other side\n";
	std::cout << *a << std::endl;
	try
	{
		NumberAr[8] = 4;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}