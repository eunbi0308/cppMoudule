#pragma once

# define RED "\033[1;91m"
# define DEFAULT "\033[0m"

#include <iostream>

struct Data
{
	int value;
	Data(int i) : value(i) {}
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};