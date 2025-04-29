#include <iostream>
#include <string.h>

// Function returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs

std::string::size_type find_char(const std::string &s, char c,
	std::string::size_type &occurs)
{
	// create a new variable and figure out its type
	// based on the expression.
	auto ret = s.size(); // start with ret being "not found"
	occurs = 0;
	// set the occurrence count parameter
	for (decltype(ret) i = 0; i != s.size(); ++i) {
		if (s[i] == c) {
			if (ret == s.size()) // if it's the same position, so only first time we find 'h'
				ret = i; // remember the first occurrence of c
			++occurs; // increment the occurrence count
		}
	}
	return ret;
	// count is returned implicitly in occurs
}

int main(int argc, char **argv){
	if (argv[1]){
		char c;
		std::string::size_type occurs;

		std::string input(argv[1]);
		std::cout << "Enter one character: " << std::endl;
		std:: cin >> c;

		std::string::size_type first_occur = find_char(input, c, occurs);

		if (first_occur < input.size())
			std::cout << "First occur of "<< c << " happens at position: "
				<< first_occur << std::endl;
		else
			std::cout << c << " not found in the string" << std::endl;
		std::cout << c << " occurs " << occurs << " times." << std::endl;
	}
	return 0;
}
