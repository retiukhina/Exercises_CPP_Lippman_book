#include <iostream>

/* Function illustrates how name is defined and used within different blocks - main function and for statement.*/

int main(){
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
}