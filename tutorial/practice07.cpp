#include <iostream>

int	main()
{
	//do/while loop : the loop will always be executed at least once, even if the condition is false.
	int	i = 0;
	do
	{
		std::cout << i << "\n";
		i++;
	} while (i < 5);
	
	//for loop
	for (int i = 1; i <= 2; ++i)
	{
		std::cout << "Outer: " << i << "\n";
		for (int j = 1; j <= 3; ++j)
		{
			std::cout << "Inner: " << j << "\n";
		}
	}

	//for each loop (C++ 2011)
	// for (type variableName : arrayName)
	int	myNumbers[5] = {10, 20, 30, 40, 50};
	for (int i : myNumbers)
	{
		std::cout << i << "\n";
	}

	//continue with for loop
	for (int i = 0; i < 10; i++)
	{
		if (i == 4)
			continue;
		std::cout << i << "\n";
	}

	//continue with while loop
	int i = 0;
	while (i < 10)
	{
		if (i == 4)
		{
			i++;
			continue;
		}
		std::cout << i << "\n";
		i++;
	}
	return (0);
}