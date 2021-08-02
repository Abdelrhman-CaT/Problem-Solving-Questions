#include <iostream>
using namespace std;

char type(char x) {
	if (x >= 65 && x <= 90) {
		return 'c';
	}
	else if (x >= 97 && x <= 122) {
		return 's';
	}
	else {
		return 'x';
	}
}

int main() {
	string name;
	cin >> name;
	int c = 0;
	int s = 0;
	for (int i = 0; i < name.length(); i++) {
		if (type(name[i]) == 'c') {
			c += 1;
		}
		else if (type(name[i]) == 's') {
			s += 1;
		}
	}

	if (c > s) {
		// to uppercase
		for (int i = 0; i < name.length(); i++) {
			if (type(name[i]) == 's') {
				name[i] -= 32;
			}
		}
	}
	else if (s >= c) {
		// to lowercase
		for (int i = 0; i < name.length(); i++) {
			if (type(name[i]) == 'c') {
				name[i] += 32;
			}
		}
	}

	cout << name;

	return 0;
}