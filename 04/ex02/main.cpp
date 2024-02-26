#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	{
		std::cout << RED << "------------- TEST 1 -------------" << DEFAULT << std::endl;
		// const AAnimal *meta = new AAnimal(); // Abstract class, cannot be directly instantiated.
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		delete j; //should not create a leak
		delete i;
	}
	{
		std::cout << std::endl;
		std::cout << RED << "------------- TEST 2 -------------" << DEFAULT << std::endl;
		int				arraySize = 10;
		const AAnimal	*animalArray[arraySize];

		for (int i = 0; i < arraySize; i++)
		{
			if (i < arraySize / 2)
				animalArray[i] = new Cat();
			else
				animalArray[i] = new Dog();	
		}
		/** Print array values**/
		for (int i = 0; i < arraySize; i++)
		{
			std::cout << "No." << i + 1 << "\t" + animalArray[i]->getType() << std::endl;
		}
		/** Delete array **/
		for (int i = 0; i < arraySize; i++)
		{
			delete animalArray[i];
		}
	}
	{
		std::cout << std::endl;
		std::cout << RED << "------------- TEST 3 -------------" << DEFAULT << std::endl;
	
		int		arraySize = 10;
		AAnimal	*animalArray[arraySize];

		for (int i = 0; i < arraySize; i++)
		{
			if (i < arraySize / 2)
				animalArray[i] = new Cat();
			else
				animalArray[i] = new Dog();	
		}
		/** Print array values**/
		for (int i = 0; i < arraySize; i++)
		{
			std::cout << "No." << i + 1 << "\t" + animalArray[i]->getType() << std::endl;
		}
		/** Put ideas in a brain**/
		int		index = 3;
		Brain	*brain;
		brain = &animalArray[index]->getBrain();
		/** Fill indeas in the ideas array **/
		if (animalArray[index]->getType() == "Cat")
		{
			for (size_t i = 0; i < brain->getIdeasArraySize(); i++)
			{
				brain->setIdea("Open my can Human thingy.\n", i);
			}
		}
		else if (animalArray[index]->getType() == "Dog")
		{
			for (size_t i = 0; i < brain->getIdeasArraySize(); i++)
			{
				brain->setIdea("Pet me Pet me Pet me.\n", i);
			}
		}
		/** Print ideas **/
		std::cout << YELLOW << brain->getIdea(0) << DEFAULT;
		std::cout << YELLOW << brain->getIdea(10) << DEFAULT;
		std::cout << YELLOW << brain->getIdea(99) << DEFAULT;

		/** Delete array **/
		for (int i = 0; i < arraySize; i++)
		{
			delete animalArray[i];
		}
	}
	{
		std::cout << std::endl;
		std::cout << RED << "-------------- TEST 4 --------------" << std::endl;
		std::cout << "Reference & operator overload" << std::endl;
		std::cout << "------------------------------------" << DEFAULT << std::endl;

		int		arraySize = 2;
		AAnimal	*animalArray[arraySize];

		for (int i = 0; i < arraySize; i++)
		{
			if (i < arraySize / 2)
				animalArray[i] = new Cat();
			else
				animalArray[i] = new Dog();	
		}

		/** Print array values**/
		for (int i = 0; i < arraySize; i++)
		{
			std::cout << "No." << i + 1 << "\t" + animalArray[i]->getType() << std::endl;
		}
		/** Put ideas in a brain**/
		int		index = 0;
		Brain	*brain = &animalArray[index]->getBrain();
		/** Fill indeas in the ideas array **/
		if (animalArray[index]->getType() == "Cat")
		{
			for (size_t i = 0; i < brain->getIdeasArraySize(); i++)
			{
				brain->setIdea("Open my can.\n", i);
			}
		}
		else if (animalArray[index]->getType() == "Dog")
		{
			for (size_t i = 0; i < brain->getIdeasArraySize(); i++)
			{
				brain->setIdea("Pet me Pet me Pet me.\n", i);
			}
		}

   		std::cout << "\n*** Assigning Cat *** \n";
			// Cat Reference
		std::cout << GREY << "Cat Reference" << DEFAULT << std::endl;
		Cat&    catRef = dynamic_cast<Cat&>(*animalArray[0]);
		// Copy assignment operator is called
		std::cout << GREY << "Copy assignment operator is called" << DEFAULT << std::endl;
		Cat    *copyCat2 = new Cat;
		*copyCat2 = dynamic_cast<Cat&>(*animalArray[0]);

   		std::cout << "\n*** Assigning Brain *** \n";
		Brain*	brainCatRef = &catRef.getBrain();
		Brain*	brainCopyCat2 = &copyCat2->getBrain();

		/** Print ideas **/
		std::cout << YELLOW << "original : " << brain->getIdea(10) << DEFAULT;
		std::cout << YELLOW << "catRef : " << brainCatRef->getIdea(10) << DEFAULT;
		std::cout << YELLOW << "copyCat2 : " << brainCopyCat2->getIdea(10) << DEFAULT;
		std::cout << std::endl;
	
		delete copyCat2;

		/** Delete array **/
		for (int i = 0; i < arraySize; i++)
		{
			delete animalArray[i];
		}
	}
	{
		std::cout << std::endl;
		std::cout << RED << "-------------- TEST 5 --------------" << std::endl;
		std::cout << "Copy assignment operator" << std::endl;
		std::cout << "------------------------------------" << DEFAULT << std::endl;

		int		arraySize = 2;
		AAnimal	*animalArray[arraySize];

		for (int i = 0; i < arraySize; i++)
		{
			if (i < arraySize / 2)
				animalArray[i] = new Cat();
			else
				animalArray[i] = new Dog();	
		}

		/** Print array values**/
		for (int i = 0; i < arraySize; i++)
		{
			std::cout << "No." << i + 1 << "\t" + animalArray[i]->getType() << std::endl;
		}
		/** Put ideas in a brain**/
		int		index = 0;
		Brain	*brain = &animalArray[index]->getBrain();

		/** Fill indeas in the ideas array **/
		if (animalArray[index]->getType() == "Cat")
		{
			for (size_t i = 0; i < brain->getIdeasArraySize(); i++)
			{
				brain->setIdea("Open my can.\n", i);
			}
		}
		else if (animalArray[index]->getType() == "Dog")
		{
			for (size_t i = 0; i < brain->getIdeasArraySize(); i++)
			{
				brain->setIdea("Pet me Pet me Pet me.\n", i);
			}
		}

   		std::cout << RED << "\n*** Assigning an animal array copy *** " << DEFAULT << std::endl;
		AAnimal	*copyAAnimalArray[arraySize];

		for (int i = 0; i < arraySize; i++)
		{
			if (animalArray[i]->getType() == "Cat")
			{
				copyAAnimalArray[i] = new Cat();
				*dynamic_cast<Cat*>(copyAAnimalArray[i]) = *dynamic_cast<Cat*>(animalArray[i]);
			}
			else if (animalArray[i]->getType() == "Dog")
			{
				copyAAnimalArray[i] = new Dog();
				*dynamic_cast<Dog*>(copyAAnimalArray[i]) = *dynamic_cast<Dog*>(animalArray[i]);
			}
		}

		std::cout << RED << "\n*** Assigning Brain *** " << DEFAULT << std::endl;
		Brain	*copyBrain = &copyAAnimalArray[index]->getBrain();

		/** Print ideas **/
		std::cout << YELLOW << "original : " << brain->getIdea(10) << DEFAULT;
		std::cout << YELLOW << "original : " << &brain << DEFAULT << std::endl;
		std::cout << YELLOW << "copied array : " << copyBrain->getIdea(10) << DEFAULT;
		std::cout << YELLOW << "copied array : " << &copyBrain << DEFAULT << std::endl;

		std::cout << std::endl;
		std::cout << RED << "-------------- TEST 6 --------------" << std::endl;
		std::cout << "Sounds test" << std::endl;
		std::cout << "------------------------------------" << DEFAULT << std::endl;

		animalArray[0]->makeSound(); // Cat
		animalArray[1]->makeSound(); // Dog
		std::cout << std::endl;
		
		/** Delete array **/
		for (int i = 0; i < arraySize; i++)
		{
			delete animalArray[i];
			delete copyAAnimalArray[i];
		}
	}
}
