#include "iostream"
using namespace std;

int main() {
	long long n, k, oddMargin,res=0;
	cin >> n >> k;
	
	if (n % 2 == 0) { // even
		oddMargin = n / 2;
		if (k <= oddMargin) {
			res = (n - 1) - ((oddMargin - k) * 2);
		}
		else if (k > oddMargin) {
			res = 2 + ((k - oddMargin) - 1) * 2;
		}
	}
	else { // odd
		oddMargin = (n + 1) / 2;
		if (k <= oddMargin) {
			res = (n) - ((oddMargin - k) * 2);
		}
		else if (k > oddMargin) {
			res = 2 + ((k - oddMargin) - 1) * 2;
		}
	}
	
	cout << res;

	return 0;
}