#include <iostream>

//Default parameter value
void	myFunction(std::string country = "Norway")
{
	std::cout << country << "\n";
}


int	main()
{
	myFunction("The Netherlands");
	myFunction("South Korea");
	myFunction();
	myFunction("Spain");

	return(0);
}