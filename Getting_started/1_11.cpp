#include <iostream>

/*  Exercise 1.11: Write a program that prompts the user for two integers. Print each number in the range specified by those two integers. */

int main()
{
	int v1 = 0, v2 = 0, v3 = 0;
	std::cout << "Enter two integer: " << std::endl;
	std::cin >> v1 >> v2;

	if (v1 < v2)
	{
		v3 = v1;
		std::cout << " The range between " << v1 << " and " << v2 << " is " << std::endl;
		while (v3 <= v2)
		{
			std::cout << v3 << std::endl;
			v3++;

		}
	}
	else
	{
		v3 = v2;
		std::cout << " The range between " << v2 << " and " << v1 << " is " << std::endl;
		while (v3 <= v1)
		{
			std::cout << v3 << std::endl;
			v3++;
		}
	}
	return (0);
}
