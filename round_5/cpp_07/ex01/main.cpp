#include "iter.hpp"


void printnumber(int n)
{
std::cout << n << std::endl;
}

void times3(int& num)
{
	num *= 3;
}

int  main()
{
	int arr[4] = {1, 2, 3, 4};
	const int arr2[4] = {1, 2, 3, 4};
	iter(arr, 4, times3);
	for(int i = 0 ; i < 4; i++)
		std::cout << arr[i] << std::endl;
	iter(arr2, 4, printnumber);
}