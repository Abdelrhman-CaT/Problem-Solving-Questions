#include <iostream>

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partitioning(int arr[], int start, int end) {
	int mid = (start + end) / 2;
	swap(&arr[mid], &arr[start]);
	int pivot = arr[start];
	int smallIn = start;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] < pivot) {
			smallIn++;
			swap(&arr[i], &arr[smallIn]);
		}
	}

	swap(&arr[smallIn], &arr[start]);
	return smallIn;
}

void quickSort(int arr[], int start, int end) {
	if (start < end) {
		int pivotLoc = partitioning(arr, start, end);
		quickSort(arr, start, pivotLoc - 1);
		quickSort(arr, pivotLoc + 1, end);
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	int* arr;
	arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	quickSort(arr, 0, n-1);

	int start = 0;
	int end = n - 1;

	while (start <= end) {
		if (arr[start] + arr[end] == k) {
			cout << "Yes\n" << arr[start] << " " << arr[end];
			delete[]arr;
			return 0;
		}
		else if (arr[start] + arr[end] < k) {
			start += 1;
		}
		else if (arr[start] + arr[end] > k) {
			end -= 1;
		}

	}

	cout << "No";
	delete[]arr;
	return 0;
}