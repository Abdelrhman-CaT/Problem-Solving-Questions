#include "iostream"
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
		if (arr[i] > pivot) {
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


int maxInd(int arr[], int start, int end) {
	if (start == end) {
		return start;
	}

	int mid = (start + end) / 2;

	int max1 = maxInd(arr, start, mid);
	int max2 = maxInd(arr, mid+1, end);

	if (arr[max1] >= arr[max2]) {
		return max1;
	}
	else {
		return max2;
	}
}

int main() {
	int n;
	cin >> n;

	int count;
	int* arr;
	arr = new int[n];
	int* arr2;
	arr2 = new int[n];
	int checked;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		count = 0;
		checked = 0;
		if (i == 0) {
			checked = 0;
		}
		else {
			if (arr[i] == arr[i - 1]) {
				checked = 1;
			}
		}
		
		if (checked == 0) {
			for (int j = 0; j < n; j++) {
				if (arr[i] == arr[j]) {
					count += 1;
				}
			}
			arr2[i] = count;
		}
		else {
			arr2[i] = 0;
		}
	}
	
	
	int max = maxInd(arr2, 0, n - 1);

	
	cout << arr[max];

	/*
	for (int i = 0; i < n; i++) {
		cout << arr2[i] << " ";
	}
	*/
	delete[]arr;
	delete[]arr2;
	return 0;
}