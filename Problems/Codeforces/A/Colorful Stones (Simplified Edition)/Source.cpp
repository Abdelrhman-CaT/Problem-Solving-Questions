#include <iostream>
using namespace std;

int main() {
	string s;
	string t;
	int position = 0;
	char curr_instruction;
	char curr_position;
	cin >> s;
	cin >> t;
	curr_position = s[position];

	for (int i = 0; i < t.length(); i++) {
		curr_instruction = t[i];
		if(curr_instruction == curr_position){
			position += 1;
			curr_position = s[position];
		}
	}

	cout << position + 1;



	return 0;
}