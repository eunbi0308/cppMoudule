#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		std::cout << "------------- TEST 1 -------------" << std::endl;
		Animal	myAnimal;
		Cat		myCat;
		Dog		myDog;

		myAnimal.makeSound();
		myCat.makeSound();
		myDog.makeSound();
	}
	{
		std::cout << std::endl;
		std::cout << "------------- TEST 2 -------------" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		meta->makeSound();
		i->makeSound(); //will output the cat sound!
		j->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << std::endl;
		std::cout << "------------- TEST 3 (Wrong) -------------" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;

		meta->makeSound();
		i->makeSound(); //will output the cat sound!

		delete meta;
		delete i;
	}
}