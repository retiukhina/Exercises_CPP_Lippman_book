#include "Sales_item.h"

/* The bookstore program reads a file of sales transactions and produces a report that shows, for each book,
the total number of copies sold, the total revenue, and the average sales price. We’ll assume
that all the transactions for each ISBN are grouped together in the input. */

int main()
{
	Sales_item total; // variable to hold data for the next transaction

	// read the first transaction and ensure that there are data to process
	if (std::cin >> total)
	{
		Sales_item trans; // variable to hold the running sum
		// read and process the remaining transactions
		while (std::cin >> trans)
		{
			// if we’re still processing the same book
			if (total.isbn() == trans.isbn())
				total += trans; // update the running total
			else
			{
				// print results for the previous book
				std::cout << total << std::endl;
				total = trans; // total now refers to the next book
			}
		}
		std::cout << total << std::endl; // print the last transaction
	}
	else
	{ // no input! warn the user
		std::cerr << "No data?!" << std::endl;
		return -1; // indicate failure
	}
	return 0;
}
