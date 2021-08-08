#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	char start = 'a';
	char end = 'z';
	int unique = 0;
	int redundant_index = 0;
	string res = "";

	for (int i = 0; i < n; i++) {
		if (start <= end && unique < k) {
			res += start;
			unique += 1;
			if (unique != k) {
				start += 1;
			}
		}
		else if (start <= end && unique >= k) {
			res += start;
		}
		else {
			start = 'a';
			res += start;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		while (res[i] == res[i + 1]) {
			res[i + 1] = res[redundant_index];
			redundant_index += 1;
		}
	}

	cout << res;

	return 0;
}