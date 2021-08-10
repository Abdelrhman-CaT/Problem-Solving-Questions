#include<iostream>
#include <vector>
using namespace std;


int main() {
	int n, k;
	int res = 0;
	cin >> n >> k;

	vector<int> contest(n);
	for (int i = 0; i < n; i++) {
		cin >> contest[i];
	}

	for (int i = 0; i < n; i++) {
		if (contest[i] >= contest[k - 1] && contest[i] > 0) {
			res += 1;
		}
	}

	cout << res;

	return 0;
}