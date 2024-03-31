#include "Scalar.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "USAGE : ./convert 'number'" << std::endl;
		return EXIT_FAILURE;
	}
	ScalarConverter::convert(argv[1]);
}