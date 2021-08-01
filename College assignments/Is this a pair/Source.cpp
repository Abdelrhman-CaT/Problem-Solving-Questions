#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int s;
	cin >> s;
	int n;
	cin >> n;

	vector<int> arr(s);
	for (int i = 0; i < s; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int start = 0;
	int finish = s - 1;

	while (start < finish && start != finish) {
		if (arr[start] + arr[finish] == n) {
			cout << "YES";
			return 0;
		}
		else if (arr[start] + arr[finish] < n) {
			start += 1;
		}
		else if (arr[start] + arr[finish] > n) {
			finish -= 1;
		}
	}

	cout << "NO";

	return 0;
}