#pragma once

# include <iostream>
# include <string>

class Fixed
{
	private:
		int					fixedPointNumber;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &num);
		Fixed &operator=(const Fixed &num);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};