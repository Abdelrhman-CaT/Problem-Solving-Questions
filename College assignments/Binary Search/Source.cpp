#include <iostream>

using namespace std;

int binarySearch(int arr[], int start, int finish, int n) {
	if (start == finish) {
		if (arr[finish] == n) {
			return finish;
		}
		else {
			return -1;
		}
	}

	int mid = (start + finish) / 2;
	if (n == arr[mid]) {
		return mid;
	}
	else if (n < arr[mid]) {
		for (int i = start; i < mid; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return binarySearch(arr, start, mid-1, n);
	}
	else if (n > arr[mid]) {
		for (int i = mid+1; i <= finish; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return binarySearch(arr, mid+1, finish, n);
	}
}


int main() {

	int n;
	cin >> n;
	int size;
	cin >> size;
	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	if (binarySearch(arr, 0, size - 1, n) != -1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	delete[]arr;

	return 0;
}