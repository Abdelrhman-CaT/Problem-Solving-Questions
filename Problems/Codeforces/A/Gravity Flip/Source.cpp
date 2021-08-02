#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x(n);

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	// sorting
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (x[j] > x[j + 1]) {
				// swap
				int temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << x[i];
		if (i != n - 1) {
			cout << " ";
		}
	}

	return 0;
}