#include <iostream>
#include <string>
#include "../../includes/Sales_data.h"

/* Our other task is to check that the transactions are for the same ISBN. If so, we’ll
print their sum, otherwise, we’ll print an error message:*/

int main()
{
	Sales_data data1, data2;
	double price = 0;
	// code to read into data1 and data2
	std::cin >> data1.book_no >> data1.units_sold >> price;
	// calculate total revenue from price and units_sold
	data1.revenue = data1.units_sold * price;
	// read the second transaction
	std::cin >> data2.book_no >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;
	if (data1.book_no == data2.book_no) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		// print: ISBN, total sold, total revenue, average price per book
		std::cout << data1.book_no << " " << totalCnt
			<< " " << totalRevenue << " ";
		if (totalCnt != 0)
			std::cout << totalRevenue/totalCnt << std::endl;
		else
			std::cout << "(no sales)" << std::endl;
		return 0; // indicate success
	} else { // transactions weren’t for the same ISBN
		std::cerr << "Data must refer to the same ISBN"
			<< std::endl;
		return -1; // indicate failure
		}
	return 0;
}
