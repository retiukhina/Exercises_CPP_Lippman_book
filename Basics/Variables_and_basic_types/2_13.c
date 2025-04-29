#include <iostream>

/* small function to show how the global variable name is reused in block scope */
int i = 42;

int main()
{
    int i = 100;
    int j = i;
    std::cout << j << std::endl;
    return 0;
}