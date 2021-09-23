#include <iostream>
#include <vector>
using namespace std;



int apply_pattern(string s, string p, int i, int j, vector<vector<int>>* x) { // i is index from s and j is index from p
	vector<vector<int>> state = *x;
	if (i < 0 && j < 0) { // both the string and the pattern are empty
		return 1;
	}
	if (j < 0) {  // only pattern is empty
		return 0;
	}
	if (i < 0) { // only string is empty
		while (j >= 0) {
			if (p[j] != '*') {
				return 0;
			}
			j--;
		}
		return 1;
	}
	
	if (state[i][j] == -1) {
		if (p[j] == '*') {
			// check if '*' stands for at least one character or nothing
			state[i][j] = apply_pattern(s, p, i - 1, j, &state) || apply_pattern(s, p, i, j - 1, &state);
		}
		// check if the corresponding characters match
		else if(p[j] != s[i] && p[j] != '?') {
			// no? then the pattern doen't match
			state[i][j] = 0;
		}
		else {
			// yes? go to the previous character in both the string and pattern
			state[i][j] = apply_pattern(s, p, i - 1, j - 1, &state);
		}
	}

	return state[i][j];
}

int main() {
	string s, p;
	cout << "s = ";
	cin >> s;
	cout << "p = ";
	cin >> p;

	vector<vector<int>> state(s.length(), vector<int>(p.length(), -1));

	if (apply_pattern(s, p, s.length() - 1, p.length() - 1, &state)) {
		cout << "true";
	}
	else {
		cout << "false";
	}

	return 0;
}