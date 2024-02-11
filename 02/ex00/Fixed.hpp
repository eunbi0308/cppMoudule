#pragma once

# include <iostream>

class Fixed
{
	private:
		int					fixedPointNumber;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		// Reinitializing. Allocating a memory instead of copying a reference.
		Fixed(const Fixed &num);
		// Overloading a copy assignment : allocating memory for a new object
		// instead of copying the reference of the original class.
		Fixed &operator=(const Fixed &num);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};


// Car car1 = new Car("blue", 4);
// Car car2 = car1;
// Car car3 = new Car(&car1); <- copy constructor : copy all the values of car1
