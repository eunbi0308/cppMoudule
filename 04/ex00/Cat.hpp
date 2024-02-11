#pragma once

# include "Animal.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat &);
		Cat &operator=(const Cat &);
		~Cat();

		void	makeSound() const;
};