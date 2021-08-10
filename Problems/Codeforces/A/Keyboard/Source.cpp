#include <iostream>
using namespace std;


int main() {
	string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";

	char direction;
	int index;
	string input;
	string message = "";
	cin >> direction >> input;

	if (direction == 'R') {
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == 'q') {
				message += 'q';
			}
			else {
				index = keyboard.find(input[i]);
				message += keyboard[index - 1];
			}
		}
	}
	else if (direction == 'L') {
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '/') {
				message += '/';
			}
			else {
				index = keyboard.find(input[i]);
				message += keyboard[index + 1];
			}
		}
	}

	cout << message;

	return 0;
}