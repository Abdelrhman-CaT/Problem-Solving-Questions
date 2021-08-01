#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int s;
	cin >> s;
	int n;
	cin >> n;
	int count = 0;

	vector<int> arr(s);
	for (int i = 0; i < s; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int start = 0;
	int finish = s - 1;

	while (start < finish) {
		if (arr[start] + arr[finish] == n) {
			count += 1;
			if (arr[start] == arr[start + 1]) {
				start += 1;
			}
			else if (arr[finish] == arr[finish - 1]) {
				finish -= 1;
			}
			else {
				start += 1;
				finish -= 1;
			}
		}
		else if (arr[start] + arr[finish] < n) {
			start += 1;
		}
		else if (arr[start] + arr[finish] > n) {
			finish -= 1;
		}
	}

	cout << count;

	return 0;
}