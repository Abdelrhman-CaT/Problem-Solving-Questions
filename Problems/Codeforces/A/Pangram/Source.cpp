#include<iostream>
#include<vector>
using namespace std;


int main() {
	int n;
	int diff;
	vector<bool> checked(26, false);
	cin >> n;

	string s;
	cin >> s;

	if (n < 26) {
		cout << "NO";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				// small
				diff = s[i] - 'a';
				checked[diff] = true;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				// cap
				diff = s[i] - 'A';
				checked[diff] = true;
			}
		}

		for (int i = 0; i < 26; i++) {
			if (checked[i] == false) {
				cout << "NO";
				return 0;
			}
		}

		cout << "YES";
	}

	return 0;
}