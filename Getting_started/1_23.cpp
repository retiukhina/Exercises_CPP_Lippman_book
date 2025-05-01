#include "../includes/Sales_item.h"

/*Exercise 1.23: Write a program that reads several transactions and counts how many
transactions occur for each ISBN .*/

int main()
{
	Sales_item item;
	std::string cur_isbn, next_isbn;
	int count = 0;

	if (std::cin >> item)
	{
		cur_isbn = item.isbn();
		count++;
		while (std::cin >> item)
		{
			next_isbn = item.isbn();
			if (cur_isbn == next_isbn)
			{
				count++;
			}
			else
			{
				std::cout << "Transaction " << cur_isbn << " occured "
					<< count << " times " << std::endl;
				count = 1;
				cur_isbn = next_isbn;
			}
		}
		std::cout << "Transaction " << cur_isbn << " occured "
			<< count << " times " << std::endl;
	}
	else
	{
		std::cout << "Error: enter transactions for ISBNs which you want to calculate.\nThe records for each ISBN should be grouped together."
			<< std::endl;
		return -1;
	}
	return 0;
}
