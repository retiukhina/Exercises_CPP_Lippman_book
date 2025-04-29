#include <iostream>

/* The function illustrates what happens with objects after operations via references*/

int main(){
    int i = 0, &r1 = i; 
    double d = 0, &r2 = d;
    
    r2 = 3.14159; // d initialized to  3.14159
    std::cout << r2 << " " << d << std::endl;
    r2 = r1; // d initialized to 0
    std::cout << r2 << " " << d << std::endl;
    i = r2; // i initialized to 0
    std::cout << i << std::endl;
    r1 = d; // i initialized to 0
    std::cout << r1 << " " << d << std::endl;
}