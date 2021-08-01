#include "iostream"
using namespace std;

int main() {
	int n;
	int coins[100];
	int tmp;
	int left = 0;
	int taken = 0;
	int count = 1;
	int start = 1;
	
	// input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	// sorting descendantly
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (coins[j] < coins[i]) {
				tmp = coins[i];
				coins[i] = coins[j];
				coins[j] = tmp;
			}
		}
	}
	
	taken = coins[0];

	for (int i = 0; i < n; i++) {
		left = 0;
		for (int i = start; i < n; i++) {
			left += coins[i];
		}

		if (taken > left) {
			break;
		}
		else {
			taken += coins[start];
			start += 1;
			count += 1;
		}
		
	}

	cout << count;

	return 0;
}