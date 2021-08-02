#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	int num_problems = 0;
	int num_sure;
	cin >> n;
	vector<vector<int>> x(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> x[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		num_sure = 0;
		for (int j = 0; j < 3; j++) {
			if (x[i][j] == 1) {
				num_sure += 1;
			}
		}
		if (num_sure >= 2) {
			num_problems += 1;
		}
	}

	cout << num_problems;

	return 0;
}