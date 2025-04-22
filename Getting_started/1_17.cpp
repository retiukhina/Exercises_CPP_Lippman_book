#include  <iostream>

/* use an if to write a program to count how many consecutive times
each distinct value appears in the input */

int main()
{
	// currVal is the number we’re counting; we’ll read new values into val
	int currVal = 0, val = 0;
	// read first number and ensure that we have data to process
	if (std::cin >> currVal)
	{
		int cnt = 1; // store the count for the current value we're processing
		while (std::cin >> val)
		{
			if (val == currVal)
				++cnt;
			else
			{
				std::cout << currVal << " occurs "
					<< cnt << " times " << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		// rememeber to print the count for the last value in the file
		std::cout << currVal << " occurs "
			<< cnt << " times " << std::endl;
	}
	return 0;
}
