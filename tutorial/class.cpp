#include <iostream>

// Polymorphism ses those methods to perform different tasks.
// This allows us to perform a single action in different ways.

//Base Class
class AAnimal {
	public:
		void animalSound() {
			std::cout << "The animal makes a sound \n";
		}
};

//Derived class
class Pig : public AAnimal {
	public:
		void animalSound() {
			std::cout << "The pig says: wee wee\n";
		}
};

//Derived class
class Dog : public AAnimal {
	public:
		void animalSound() {
			std::cout << "The dog says: bow wow \n";
		}
};

int	main()
{
	AAnimal	myAnimal;
	Pig		myPig;
	Dog		myDog;

	myAnimal.animalSound();
	myPig.animalSound();
	myDog.animalSound();

	return 0;
}
