#include "iostream"
using namespace std;

bool isNotVowel(char x) {
	if (x == 65 || x == 97 || x == 69 || x == 101 || x == 73 || x == 105 || x == 79 || x == 111 || x == 85 || x == 117 || x == 89 || x == 121) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	string s;
	cin >> s;
	int n = s.length();
	string new_S = "";
	for (int i = 0; i < n; i++) {
		if (isNotVowel(s[i])) {
			if (s[i] < 97)
			{
				s[i] += 32;
			}
			new_S += '.';
			new_S += s[i];
		}
	}
	cout << new_S;
	return 0;
}