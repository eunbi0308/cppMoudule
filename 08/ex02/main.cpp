#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << PURPLE << "\n_____ Subject test\n\n" << DEFAULT;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();
		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
		std::cout << GREEN << "___ Stack s" << "\n" << DEFAULT;
		std::stack<int> temp = s;

		while (!temp.empty())
		{
			int top = temp.top();
			std::cout << top << "\n";
			temp.pop();
		}
	}
	{
		std::cout << PURPLE << "\n_____ std::list\n\n" << DEFAULT;
		std::list<int> listStack;
		listStack.push_back(5);
		listStack.push_back(17);

		std::cout << listStack.back() << std::endl;

		listStack.pop_back();
		std::cout << listStack.size() << std::endl;

		listStack.push_back(3);
		listStack.push_back(5);
		listStack.push_back(737);
		//[...]
		listStack.push_back(0);

		std::list<int>::iterator it = listStack.begin();
		std::list<int>::iterator ite = listStack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << PURPLE << "\n_____ Default test\n" << DEFAULT;
		std::cout << GREEN << "___ Default constructor" << "\n" << DEFAULT;
		MutantStack<int> mstack;
		std::cout << "MutantStack size : "  << mstack.size() << "\n";
		std::cout << GREY << "Adding numbers..." << "\n" << DEFAULT;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		std::cout << "MutantStack size : "  << mstack.size() << "\n";
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		std::cout << "< MutantStack elements >" << "\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << GREEN << "___ Copy constructor" << "\n" << DEFAULT;
		MutantStack<int> mstack2 = mstack;
		std::cout << "MutantStack2 size : "  << mstack2.size() << "\n";

		std::cout << "< MutantStack2 elements >" << "\n";
		it = mstack2.begin();
		ite = mstack2.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << GREEN << "___ Copy assignment operater" << "\n" << DEFAULT;
		MutantStack<int> mstack3;
		std::cout << GREY << "Adding numbers..." << "\n" << DEFAULT;
		mstack3.push(9);
		mstack3.push(8);
		mstack3.push(7);
		mstack3.push(6);
		std::cout << "MutantStack3 size : "  << mstack3.size() << "\n";
		it = mstack3.begin();
		ite = mstack3.end();

		std::cout << "< MutantStack3 elements >" << "\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		mstack3 = mstack;
		std::cout << "MutantStack3 size : "  << mstack3.size() << "\n";
		
		std::cout << "< MutantStack3 elements >" << "\n";
		it = mstack3.begin();
		ite = mstack3.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << GREEN << "___ Different data type stack" << "\n" << DEFAULT;
		
		MutantStack<std::string> mstack;

		mstack.push("Hello ");
		mstack.push("This ");
		mstack.push("is ");
		mstack.push("a string ");
		mstack.push("mstack.");

		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();

		while (it != ite)
		{
			*it += 10;
			std::cout << *it;
			++it;
		}
	}
	{
		std::cout << GREEN << "___ Change value of stack elements by using iterator" << "\n" << DEFAULT;
		
		MutantStack<int> mstack;

		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		std::cout << PINK << "Adding 10 to each numbers..." << "\n" << DEFAULT;
		while (it != ite)
		{
			*it += 10;
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << PINK << "Changing all numbers into 88..." << "\n" << DEFAULT;
		it = mstack.begin();
		ite = mstack.end();
		while (it != ite)
		{
			*it = 88;
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << GREEN << "___ Change value of stack elements by using iterator" << "\n" << DEFAULT;
		
		MutantStack<int> mstack;

		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		std::cout << PINK << "Adding 10 to each numbers..." << "\n" << DEFAULT;
		while (it != ite)
		{
			*it += 10;
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << PINK << "Changing all numbers into 88..." << "\n" << DEFAULT;
		it = mstack.begin();
		ite = mstack.end();
		while (it != ite)
		{
			*it = 88;
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << GREEN << "___ Constant interator" << "\n" << DEFAULT;
		
		MutantStack<int> mstack;

		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();

		std::cout  << "< elements >" << "\n" << DEFAULT;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << PINK << "Attempt to modify a value" << "\n" << DEFAULT;
		// *it = 88;	
	}
	return 0;
}