#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string games;
	cin >> games;
	int a = 0;
	int d = 0;
	for (int i = 0; i < n; i++) {
		if (games[i] == 'A') {
			a += 1;
		}
		else if (games[i] == 'D') {
			d += 1;
		}
	}

	if (a > d) {
		cout << "Anton";
	}
	else if (a < d) {
		cout << "Danik";
	}
	else {
		cout << "Friendship";
	}

	return 0;
}