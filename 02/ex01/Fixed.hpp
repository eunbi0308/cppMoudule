#pragma once

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					fixedPointNumber;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &num);
		Fixed(const	int	intNumber);
		Fixed(const float floatNumber);
		Fixed &operator=(const Fixed &num);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void)	const;
};

// Car car1 = new Car("blue", 4);
// Car car2 = car1;
// Car car3 = new Car(&car1); <- copy constructor : copy all the values of car1
