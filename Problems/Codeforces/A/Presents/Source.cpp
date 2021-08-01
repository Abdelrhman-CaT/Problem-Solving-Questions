#include "iostream"
using namespace std;

int main() {
	int arr[100];
	int n;
	cin >> n;
	int arr2[100];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] -= 1;
	}

	for (int i = 0; i < n; i++) {
		arr2[arr[i]] = i+1;
	}

	for (int i = 0; i < n; i++) {
		cout << arr2[i];
		if (i != n - 1) {
			cout << " ";
		}
	}

	return 0;
}