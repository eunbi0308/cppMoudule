#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	// {
	// 	std::cout << "------------- TEST 1 -------------" << std::endl;
	// 	const AAnimal* j = new Dog();
	// 	const AAnimal* i = new Cat();
	// 	delete j;//should not create a leak
	// 	delete i;
	// }
	// {
	// 	std::cout << std::endl;
	// 	std::cout << "------------- TEST 2 -------------" << std::endl;
	// 	int				arraySize = 10;
	// 	const AAnimal	*animalArray[arraySize];

	// 	for (int i = 0; i < arraySize; i++)
	// 	{
	// 		if (i < arraySize / 2)
	// 			animalArray[i] = new Cat();
	// 		else
	// 			animalArray[i] = new Dog();	
	// 	}
	// 	/** Print array values**/
	// 	for (int i = 0; i < arraySize; i++)
	// 	{
	// 		std::cout << "No." << i + 1 << "\t" + animalArray[i]->getType() << std::endl;
	// 	}
	// 	/** Delete array **/
	// 	for (int i = 0; i < arraySize; i++)
	// 	{
	// 		delete animalArray[i];
	// 	}
	// }
	// {
	// 	std::cout << std::endl;
	// 	std::cout << "------------- TEST 3 -------------" << std::endl;
	
	// 	int				arraySize = 10;
	// 	AAnimal	*animalArray[arraySize];

	// 	for (int i = 0; i < arraySize; i++)
	// 	{
	// 		if (i < arraySize / 2)
	// 			animalArray[i] = new Cat();
	// 		else
	// 			animalArray[i] = new Dog();	
	// 	}
	// 	/** Print array values**/
	// 	for (int i = 0; i < arraySize; i++)
	// 	{
	// 		std::cout << "No." << i + 1 << "\t" + animalArray[i]->getType() << std::endl;
	// 	}
	// 	/** Put ideas in a brain**/
	// 	int		index = 3;
	// 	Brain	brain = animalArray[index]->getBrain();
	// 	/** Fill indeas in the ideas array **/
	// 	if (animalArray[index]->getType() == "Cat")
	// 	{
	// 		for (size_t i = 0; i < brain.getIdeasArraySize(); i++)
	// 		{
	// 			brain.setIdea("Open my can Human thingy.\n", i);
	// 		}
	// 	}
	// 	else if (animalArray[index]->getType() == "Dog")
	// 	{
	// 		for (size_t i = 0; i < brain.getIdeasArraySize(); i++)
	// 		{
	// 			brain.setIdea("Pet me Pet me Pet me.\n", i);
	// 		}
	// 	}
	// 	/** Print ideas **/
	// 	std::cout << YELLOW << brain.getIdea(0) << DEFAULT;
	// 	std::cout << YELLOW << brain.getIdea(10) << DEFAULT;
	// 	std::cout << YELLOW << brain.getIdea(99) << DEFAULT;

	// 	/** Delete array **/
	// 	for (int i = 0; i < arraySize; i++)
	// 	{
	// 		delete animalArray[i];
	// 	}
	// }
	{
		std::cout << std::endl;
		std::cout << "-------------- TEST 4 --------------" << std::endl;
		std::cout << "    Reference & Copy constructor" << std::endl;
		std::cout << "------------------------------------" << std::endl;

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
		Brain	*brain = animalArray[index]->getBrain();
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
			// Copy constructor is called
		std::cout << GREY << "Copy constructor is called" << DEFAULT << std::endl;
		Cat*	copyCat = new Cat(dynamic_cast<Cat&>(*animalArray[0]));
		// Copy assignment operator is called
		std::cout << GREY << "Copy assignment operator is called" << DEFAULT << std::endl;
		Cat    *copyCat2 = new Cat;
		*copyCat2 = dynamic_cast<Cat&>(*animalArray[0]);

   		std::cout << "\n*** Assigning Brain *** \n";
		Brain*	brainCatRef = catRef.getBrain();
		Brain*	brainCopyCat = copyCat->getBrain();
		Brain*	brainCopyCat2 = copyCat2->getBrain();

		/** Print ideas **/
		std::cout << YELLOW << "original : " << brain->getIdea(10) << DEFAULT;
		std::cout << YELLOW << "catRef : " << brainCatRef->getIdea(10) << DEFAULT;
		std::cout << YELLOW << "copyCat : " << brainCopyCat->getIdea(10) << DEFAULT;
		std::cout << YELLOW << "copyCat2 : " << brainCopyCat2->getIdea(10) << DEFAULT;
		std::cout << std::endl;
	
		delete copyCat;
		delete copyCat2;

		/** Delete array **/
		for (int i = 0; i < arraySize; i++)
		{
			delete animalArray[i];
		}
		
	}
	{
		std::cout << std::endl;
		std::cout << "-------------- TEST 5 --------------" << std::endl;
		std::cout << "Copy assignment operator" << std::endl;
		std::cout << "------------------------------------" << std::endl;

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
		Brain	*brain = animalArray[index]->getBrain();

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

   		std::cout << "\n*** Assigning an animal array copy *** \n";
		AAnimal	*copyAnimalArray[arraySize];
		
		for (int i = 0; i < arraySize; ++i) 
		{
			/** 
			 	create an instance of an abstract class AAnimal, 
				which is not allowed. Abstract classes are meant to be used 
				as base classes and cannot be instantiated directly. 
			**/
			// copyAnimalArray[i] = new AAnimal();
			copyAnimalArray[i] = new Cat();
			*copyAnimalArray[i] = *animalArray[i];
		}

		std::cout << "\n*** Assigning Brain *** \n";
		Brain	*copyBrain = copyAnimalArray[index]->getBrain();

		/** Print ideas **/
		std::cout << YELLOW << "original : " << brain->getIdea(10) << DEFAULT;
		std::cout << YELLOW << "copied array : " << copyBrain->getIdea(10) << DEFAULT;
		std::cout << std::endl;
	
		/** Delete copied array **/
		for (int i = 0; i < arraySize; i++)
		{
			delete copyAnimalArray[i];
		}
	
		/** Delete array **/
		for (int i = 0; i < arraySize; i++)
		{
			delete animalArray[i];
		}
		
	}
}