#include "Array.hpp"
#include "Array.tpp"
#include "string.h"

int main()
{
	{
		// Creates a new integer object on the heap, which initially has value of 0.
		int *a = new int();
		std::cout << *a << "\n";
		delete a;

		int *b = new int(8);
		std::cout << *b << "\n";
		delete b;
	}
	{
		std::cout << PURPLE << "\n_____ Default test\n" << DEFAULT;
		std::cout << BLUE << "___ Default constructor" << "\n" << DEFAULT;
		Array<int> emptyArr;
		std::cout << "array size : " << emptyArr.size() << "\n";
		std::cout << BLUE << "___ Size constructor" << "\n" << DEFAULT;
		Array<int> intArr(3);
		intArr[0] = 0;
		intArr[1] = 1;
		intArr[2] = 2;
		std::cout << "intArr address : " << &intArr << "\n";
		std::cout << "array size : "  << intArr.size() << "\n";
		for (unsigned int i = 0; i < intArr.size(); ++i)
			std::cout << "intArr[" << i << "] : " << intArr[i] << "\n";

		std::cout << BLUE << "___ Copy constructor" << "\n" << DEFAULT;
		Array<int> intArr2 = intArr;
		std::cout << "intArr2 address : " << &intArr2 << "\n";
		std::cout << "array size : "  << intArr2.size() << "\n";
		for (unsigned int i = 0; i < intArr2.size(); ++i)
			std::cout << "intArr2[" << i << "] : " << intArr2[i] << "\n";

		std::cout << GREY << "Modifying intArr2 elements...\n" << DEFAULT;
		for (unsigned int i = 0; i < intArr2.size(); ++i)
		{
			intArr2[i] += 10;
			std::cout << "intArr2[" << i << "] : " << intArr2[i] << "\n";
		}

		std::cout << BLUE << "___ intArr elements value" << "\n" << DEFAULT;
			for (unsigned int i = 0; i < intArr.size(); ++i)
				std::cout << "intArr[" << i << "] : " << intArr[i] << "\n";

		std::cout << BLUE << "___ Copy assignment operater" << "\n" << DEFAULT;
		Array<int> intArr3;
		intArr3 = intArr;
		std::cout << "intArr3 address : " << &intArr3 << "\n";
		std::cout << "array size : "  << intArr3.size() << "\n";
		for (unsigned int i = 0; i < intArr3.size(); ++i)
			std::cout << "intArr3[" << i << "] : " << intArr3[i] << "\n";
	}
	{
		std::cout << PURPLE << "\n_____ Empty array test\n" << DEFAULT;
		try
		{
			Array<int> 	intArr;
			std::cout << sizeof(intArr) / sizeof(intArr[0]) << "\n";
			std::cout << "empty int array size : " << intArr.size() << "\n";
			std::cout << "empty int array[0] : " << intArr[0] << "\n";
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << "\n" << DEFAULT << std::endl;
		}
		try
		{
			Array<char> 	charArr;
			std::cout << sizeof(charArr) / sizeof(charArr[0]) << "\n";
			std::cout << "empty char array size : " << charArr.size() << "\n";
			std::cout << "empty char array[0] : " << charArr[0] << "\n";
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << "\n" << DEFAULT;
		}
		try
		{
			Array<std::string> 	strArr;
			std::cout << sizeof(strArr) / sizeof(strArr[0]) << "\n";
			std::cout << "empty string array size : " << strArr.size() << "\n";
			std::cout << "empty string array[0] : " << strArr[0] << "\n";
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << "\n" << DEFAULT << std::endl;
		}
	}
	{
		std::cout << PURPLE << "\n_____ Basic array test\n" << DEFAULT;
		try
		{
			Array<int> 	intArr(5);
			std::cout << "int array size : " << intArr.size() << "\n";

			std::cout << BLUE << "___ Before declaring elements value" << "\n" << DEFAULT;
				for (unsigned int i = 0; i < intArr.size(); ++i)
					std::cout << "intArr[" << i << "] : " << intArr[i] << "\n";
			intArr[0] = 0;
			intArr[1] = 1;
			intArr[2] = 2;
			intArr[3] = 3;
			intArr[4] = 4;

			std::cout << BLUE << "___ After declaring elements value" << "\n" << DEFAULT;
			for (unsigned int i = 0; i < intArr.size(); ++i)
				std::cout << "intArr[" << i << "] : " << intArr[i] << "\n";

			std::cout << BLUE << "___ Index out of bounds" << "\n" << DEFAULT;
			intArr[5] = 5;
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << "\n" << DEFAULT << std::endl;
		}
		try
		{
			Array<char> 	charArr(5);
			std::cout << "char array size : " << charArr.size() << "\n";

			std::cout << BLUE << "___ Before declaring elements value" << "\n" << DEFAULT;
			for (unsigned int i = 0; i < charArr.size(); ++i)
				std::cout << "charArr[" << i << "] : " << charArr[i] << "\n";
			charArr[0] = 'a';
			charArr[1] = 'b';
			charArr[2] = 'c';
			charArr[3] = 'd';
			charArr[4] = 'e';

			std::cout << BLUE << "___ After declaring elements value" << "\n" << DEFAULT;
			for (unsigned int i = 0; i < charArr.size(); ++i)
				std::cout << "charArr[" << i << "] : " << charArr[i] << "\n";

			std::cout << BLUE << "___ Index out of bounds" << "\n" << DEFAULT;
			charArr[-1] = 'f';
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << "\n" << DEFAULT << std::endl;
		}
		try
		{
			Array<std::string> 	strArr(5);
			std::cout << "string array size : " << strArr.size() << "\n";

			std::cout << BLUE << "___ Before declaring elements value" << "\n" << DEFAULT;
			for (unsigned int i = 0; i < strArr.size(); ++i)
				std::cout << "strArr[" << i << "] : " << strArr[i] << "\n";
			strArr[0] = "aaaaa";
			strArr[1] = "bbbbb";
			strArr[2] = "ccccc";
			strArr[3] = "ddddd";
			strArr[4] = "eeeee";

			std::cout << BLUE << "___ After declaring elements value" << "\n" << DEFAULT;
			for (unsigned int i = 0; i < strArr.size(); ++i)
				std::cout << "strArr[" << i << "] : " << strArr[i] << "\n";

			std::cout << BLUE << "___ Index out of bounds" << "\n" << DEFAULT;
			strArr[-1] = "fffff";
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << "\n" << DEFAULT << std::endl;
		}
	}
	
	return 0;
}