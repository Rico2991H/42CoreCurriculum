#include "Base.hpp"

int main()
{
	Base* obj = generate();
	identify(obj);
	identify(*obj);
}