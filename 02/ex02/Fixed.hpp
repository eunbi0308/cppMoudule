#pragma once

# define GREEN "\033[0;92m"
# define YELLOW "\e[38;5;208m"
# define RED "\033[1;91m"
# define GREY "\033[0;90m"
# define PURPLE	"\033[38;2;200;160;255m"
# define DEFAULT "\033[0m"

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
		// comparison operators
		bool operator>(const Fixed &num) const;
		bool operator<(const Fixed &num) const;
		bool operator>=(const Fixed &num) const;
		bool operator<=(const Fixed &num) const;
		bool operator==(const Fixed &num) const;
		bool operator!=(const Fixed &num) const;
		// arithmetic operators
		Fixed operator+(const Fixed &num) const;
		Fixed operator-(const Fixed &num) const;
		Fixed operator*(const Fixed &num) const;
		Fixed operator/(const Fixed &num) const;
		// increment operators
		Fixed operator++(int); // Post
		Fixed operator++(void); // Pre
		// decrement operators
		Fixed operator--(int); // Post
		Fixed operator--(void); // Pre

		// static
		static			Fixed& min(Fixed& a, Fixed& b);
		static const	Fixed& min(const Fixed& a, const Fixed& b);
		static			Fixed& max(Fixed& a, Fixed& b);
		static const	Fixed& max(const Fixed& a, const Fixed& b);

		~Fixed();

		int		getRawBits(void) const;
		int		toInt(void)	const;
		float	toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixedPoint);
