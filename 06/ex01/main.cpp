#include "Serializer.hpp"

int main()
{
	Data data(8);

	uintptr_t	serializedPtr = Serializer::serialize(&data);
	Data		*deserializedPtr = Serializer::deserialize(serializedPtr);

	std::cout << RED << "Test" << DEFAULT << std::endl;
	std::cout << "Serialized pointer: " << serializedPtr << std::endl;

	std::cout << std::endl;
	std::cout << RED << "Original & Deserialized values" << DEFAULT << std::endl;
	std::cout << "Original	: " << data.value << std::endl;
	std::cout << "Deserialized	: " << deserializedPtr->value << std::endl;

	std::cout << std::endl;
	std::cout << RED << "Original & Deserialized address" << DEFAULT << std::endl;	
	std::cout << "Original	: " << &data << std::endl;
	std::cout << "Deserialized	: " << deserializedPtr << std::endl;
}