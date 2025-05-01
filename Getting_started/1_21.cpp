#include "../includes/Sales_item.h"

/* Exercise 1.21: Write a program that reads two Sales_item objects that have the
same ISBN and produces their sum. */

int main()
{
	Sales_item item1, item2;
	//std::cin >> item1 >> item2;
	if (std::cin >> item1 && std::cin >> item2)
	{
		if (item1.isbn() == item2.isbn())
		{
			std::cout << item1 + item2 << std::endl;
		}
		else
		{
			std::cout << "Enter two transaction for the same ISBN" << std::ends;
			return -1;
		}
	}
	return 0;
}
