#include <iostream>
using namespace std;

int main() {
	int n, h;
	int width = 0;
	cin >> n;
	cin >> h;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] <= h) {
			width += 1;
		}
		else if (arr[i] > h) {
			width += 2;
		}
	}
	
	cout << width;

	return 0;
}