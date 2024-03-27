#include "Scalar.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
		return EXIT_FAILURE;
	ScalarConverter::convert(argv[1]);
}