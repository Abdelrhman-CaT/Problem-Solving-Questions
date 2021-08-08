#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, b, d;
	int total_size = 0;
	int clean_times = 0;
	cin >> n >> b >> d;

	vector<int> oranges(n);
	for (int i = 0; i < n; i++) {
		cin >> oranges[i];
	}

	for (int i = 0; i < n; i++) {
		if (oranges[i] <= b) {
			total_size += oranges[i];
			if (total_size > d) {
				clean_times += 1;
				total_size = 0;
			}
		}
	}

	cout << clean_times;

	return 0;
}