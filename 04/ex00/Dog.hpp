#pragma once

# include "Animal.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog &);
		Dog &operator=(const Dog &);
		~Dog();

		void	makeSound() const;
};