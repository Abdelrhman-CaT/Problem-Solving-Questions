#include<iostream>
#include<cmath>

using namespace std;


int main() {
	string x;
	cin >> x;
	int pointer = 97;
	int num_moves = 0;

	for (int i = 0; i < x.length(); i++) {
		int diff = x[i] - pointer;
		if (abs(diff) <= 13) {
			num_moves += abs(diff);
		}
		else {
			num_moves += (13 - (abs(diff) - 13));
		}
		pointer = x[i];
	}

	cout << num_moves;

	return 0;
}