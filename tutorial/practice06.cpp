#include <iostream>

int main()
{
	//Ternary Operator
	// variable = (condition) ? expressionTrue : expressionFalse;
	int time = 20;
	std::string result = (time < 18) ? "Good day.\n" : "Good evening.\n";
	std::cout << result;

	//Switch
	int	day = 8;
	switch (day)
	{
		case 1:
			std::cout << "Monday\n";
			break;
		case 2:
			std::cout << "Tuesday\n";
			break;
		case 3:
			std::cout << "Wednesday\n";
			break;
		case 4:
			std::cout << "Thursday\n";
			break;
		case 5:
			std::cout << "Friday\n";
			break;
		case 6:
			std::cout << "Saturday\n";
			break;
		case 7:
			std::cout << "Sunday\n";
			break;
		default:
			std::cout << "Looking forward to the weekend.\n";
	}
	return (0);
}