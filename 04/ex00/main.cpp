#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	{
		std::cout << "------------- TEST 1 -------------" << std::endl;
		AAnimal	myAnimal;
		Cat		myCat;
		Dog		myDog;

		myAnimal.makeSound();
		myCat.makeSound();
		myDog.makeSound();
	}
	{
		std::cout << std::endl;
		std::cout << "------------- TEST 2 -------------" << std::endl;
		const AAnimal* meta = new AAnimal();
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
}