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
