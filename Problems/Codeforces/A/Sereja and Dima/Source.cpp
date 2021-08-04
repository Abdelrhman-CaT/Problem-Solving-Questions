#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> cards(n);
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	int sScore = 0;
	int dScore = 0;
	bool sTurn = true;

	while (cards.size() != 0) {
		int right = cards[cards.size() - 1];
		int left = cards[0];
		if (sTurn == true) {
			sScore += (right > left) ? right : left;
			sTurn = false;
		}
		else {
			dScore += (right > left) ? right : left;
			sTurn = true;
		}
		if (right > left) {
			cards.erase(cards.end() - 1);
		}
		else {
			cards.erase(cards.begin());
		}
		
	}

	cout << sScore << " " << dScore;

	return 0;
}