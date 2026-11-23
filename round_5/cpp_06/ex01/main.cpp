#include "Serializer.hpp"

int main()
{
	Data	before;
	before.age = 34;
	before.name = "Rico";
	before.next = &before;

	Data *after = Serializer::deserialize(Serializer::serialize(&before));
	std::cout << "Hi my name is " << after->name << std::endl;
	std::cout << "I am " << after->age << " years old" << std::endl;
	std::cout << "This is my adress " << after->next << std::endl;
	return (0);
}