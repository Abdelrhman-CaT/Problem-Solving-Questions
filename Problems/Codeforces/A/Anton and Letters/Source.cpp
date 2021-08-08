#include<iostream>
#include<string>
#include<set>
using namespace std;


int main() {
	string s;
	getline(cin, s);
	set<char> distinct;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ' && s[i] != '{' && s[i] != '}' && s[i] != ',') {
			distinct.insert(s[i]);
		}
	}

	cout << distinct.size();

	return 0;
}