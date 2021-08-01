#include "iostream"
using namespace std;

int minimum(int n, int m) {
	if (n < m) {
		return n;
	}
	else
	{
		return m;
	}
}

int main() {
	int n, m, count=0;
	cin >> n >> m;

	for (int a = 0; a <= minimum(n, m); a++) {
		for (int b = 0; b <= minimum(n, m); b++) {
			if (((a * a) + b == m) && ((b * b) + a == n)) {
				count += 1;
			}
		}
	}

	cout << count;

	return 0;
}