#include <iostream>
#include <set>
using namespace std;

int num_occur(char c, string str) {
	int num = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == c) {
			num += 1;
		}
	}

	return num;
}

int main() {
	string name;
	set<char> red;
	cin >> name;
	int l = 0;

	for (int i = 0; i < name.length(); i++) {
		if (num_occur(name[i], name) == 1) {
			l += 1;
		}
		else {
			red.insert(name[i]);
		}
	}

	l += red.size();
	
	if (l % 2 == 0) {
		cout << "CHAT WITH HER!";
	}
	else {
		cout << "IGNORE HIM!";
	}

	return 0;
}