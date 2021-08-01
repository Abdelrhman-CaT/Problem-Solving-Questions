#include "iostream"
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int* arr;
	arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] + arr[j] == k) {
				cout << "Yes\n";
				if (arr[i] <= arr[j]) {
					cout << arr[i] << " " << arr[j];
				}
				else {
					cout << arr[j] << " " << arr[i];
				}
				return 0;
			}
		}
	}

	cout << "No";

	return 0;
}