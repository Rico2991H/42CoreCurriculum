#include "PMerge.hpp"

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int i = 1;
		long num;
		std::deque<int> ret;
		std::vector<int> ret2;
		PMerge Numbers;
		while(argv[i])
		{
			if (!parseArg(argv[i], num))
			{
				std::cout << "Error" << std::endl;
				return 1;
			}
			int value = static_cast<int>(num);
			Numbers.insertVec(value);
			Numbers.insertDeq(value);
			i++;
		}
		Numbers.MeasureandExecDeq(i);
		Numbers.MeasureandExecVec(i);
	}
	else
		std::cout << "requires exactly one  argument" << std::endl;
}