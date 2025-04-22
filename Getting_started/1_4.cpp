#include <iostream>

/* Exercise 1.4: Write a program that uses the multiplication operator, *, to print the product instead.*/

int main()
{
	int v1 = 0, v2 = 0;
	std::cout << "Enter two integers" << std::endl;
	std::cin >> v1 >> v2;
	std::cout << "The multiplication result of " << v1 << " * " << v2
			<< " is " << v1 * v2 << std::endl;
	return (0);
}


