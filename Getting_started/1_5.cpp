#include <iostream>

/* Exercise 1.5: Rewrite the program 1_4 to use a separate statement to print each operand. */

int main()
{
	int v1 = 0, v2 = 0;
	std::cout << "Enter two numbers:";
	std::cout << std::endl;
	std::cin >> v1;
	std::cin >> v2;
	std::cout << "The sum of ";
	std::cout << v1;
	std::cout << " and ";
	std::cout << v2;
	std::cout << " is ";
	std::cout << v1 + v2;
	std::cout << std::endl;
	return 0;
}
