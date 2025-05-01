#include <iostream>

int main(){
	int a = 3, b = 4;
	decltype(a) c = a; // c is int
	decltype((b)) d = a; // d is int&
	++c; // 4
	++d; // 4
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << a << std::endl;
}
