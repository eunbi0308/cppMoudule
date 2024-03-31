#include "Serializer.hpp"

Serializer::Serializer()
{
	#ifdef DEBUG
		std::cout << GREY << "Serializer : Default constructor called" << DEFAULT << std::endl; 
	#endif
}

Serializer::Serializer(const Serializer &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Serializer : Copy constructor called" << DEFAULT << std::endl; 
	#endif
	(void)other;
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	#ifdef DEBUG
		std::cout << GREY << "Serializer : Copy assignment operator called" << DEFAULT << std::endl; 
	#endif
	(void)other;
	return *this;
}

Serializer::~Serializer()
{
	#ifdef DEBUG
		std::cout << GREY << "Serializer : Destructor called" << DEFAULT << std::endl; 
	#endif
}

// Convert the Data object pointer into an unsigned integer(unintptr_t).
// reinterpret the bit pattern of the pointer as an integer.
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// Convert serialized unsigned integer back into a pointer to 'Data' object.
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}