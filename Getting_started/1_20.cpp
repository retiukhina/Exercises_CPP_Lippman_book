#include "../includes/Sales_item.h"

/* Exercise 1.20: Use Sales_item.h to write a program that reads a set of book sales transactions,
writing each transaction to the standard output.*/

int main()
{
	Sales_item item;

	while (std::cin >> item)
	{
		std::cout << item << std::endl;
	}
	return 0;
}
