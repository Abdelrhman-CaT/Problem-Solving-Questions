#include <iostream>
using namespace std;


int main() {
	int cals[4];
	for (int i = 0; i < 4; i++) {
		cin >> cals[i];
	}

	string game;
	cin >> game;

	int total_cals = 0;

	for (int i = 0; i < game.length(); i++) {
		int num = game[i] - '0';
		total_cals += cals[num-1];
	}

	cout << total_cals;

	return 0;
}