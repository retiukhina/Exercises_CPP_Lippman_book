#include <iostream>
#include <string>
#include <string.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string s1, s2;

	getline(cin, s1);
	getline(cin, s2);
	if (s1.empty() && s2.empty()) {
		cout << "Strings are empty." << endl;
	}
	if (s1 == s2) {
		cout << "Strings " << s1 << " and " << s2 << " are equal." << endl;
	}
	else if (s1 < s2) {
		cout << "String " << s1 << " less then " << s2 << endl;
	}
	else {
		cout << "String " << s2 << " less then " << s1 << endl;
	}
}
