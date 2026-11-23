#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN<std::string> RPNS;
		RPNS.split_input(argv[1]);		
	}
	else
		std::cerr << "Program requires one argument" << std::endl;
}