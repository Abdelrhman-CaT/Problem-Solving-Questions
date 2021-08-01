#include "iostream"
#include "string"
using namespace std;
int main() {
	int n;
	cin >> n;
	string newStr[100];
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str.length() > 10) {
			newStr[i] += str[0];
			newStr[i] += to_string(str.length() - 2);
			newStr[i] += str[str.length() - 1];
		}
		else {
			newStr[i] = str;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << newStr[i] << endl;
	}
	return 0;
}