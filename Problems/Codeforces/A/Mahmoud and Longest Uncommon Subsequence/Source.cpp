#include<iostream>
using namespace std;

// SOLVED BY KOFTA

int main() {
	string a, b;
	cin >> a >> b;

	if (a == b) {
		cout << -1;
	}
	else {
		int length = (a.length() > b.length()) ? a.length() : b.length();
		cout << length;
	}

	return 0;
}