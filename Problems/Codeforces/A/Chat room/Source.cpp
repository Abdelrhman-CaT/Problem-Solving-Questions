#include "iostream"
using namespace std;

int main() {
	int j = 0, passed = 0;
	string str;
	string auth = "hello";
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == auth[j]) {
			j += 1;
			passed += 1;
		}
		if (passed == 5) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}