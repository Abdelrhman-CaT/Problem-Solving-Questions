#include "iostream"
#include "vector"
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> res(n);
	vector<int> presesnts(n);
	for (int i = 0; i < n; i++) {
		cin >> presesnts[i];
	}

	for (int i = 0; i < n; i++) {
		res[presesnts[i]-1] = i+1;
	}

	for (int i = 0; i < n; i++) {
		cout << res[i];
		if (i != n - 1) {
			cout << " ";
		}
	}

	return 0;
}