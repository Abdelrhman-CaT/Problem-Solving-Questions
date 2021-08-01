#include "iostream"
using namespace std;

int main() {
	int n;
	int max = 0;
	int min = 0;
	int arr[100];
	int tmp;
	int count = 0;

	// input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// minimum index for maximum value
	for (int i = n-1; i >= 0; i--) {
		if (arr[i] >= arr[max]) {
			max = i;
		}
	}

	// moving the maximum value
	for (int i = max; i > 0; i--) {
		tmp = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = tmp;
		count += 1;
	}

	// maximum index for minimum value
	for (int i = 0; i < n; i++) {
		if (arr[i] <= arr[min]) {
			min = i;
		}
	}

	// moving the minimum value
	for (int i = min; i < n-1; i++) {
		tmp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = tmp;
		count += 1;
	}
	
	cout << count;

	return 0;
}