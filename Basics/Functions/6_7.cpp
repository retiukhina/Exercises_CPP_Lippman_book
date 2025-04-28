/* Write a function that returns 0 when it is first called and then generates
numbers in sequence each time it is called again. */

#include <iostream>

int count_calls(){

	static int ret = 0;
	return ret++;
}

int main(){

	int cnt;

	for (int j = 0; j < 3; ++j){
		std::cout << " Enter one integer: " << std::endl;
		std::cin >> cnt;
		if (cnt < 0){
			std::cout << " Error: enter integer more than 0" << std::endl;
			break ;
		}
		std::cout << " You increased static integer " << cnt << " times" << std::endl;
		for (size_t i = 0; i != cnt; ++i){
			std::cout << count_calls() << std::endl;
		}

	}
	return -1;
}
