#include<iostream>
#include<vector>
//#include<map>
//#include<unordered_map>
using namespace std;

int main() {
	int num_lines;
	int num_huntings;
	cin >> num_lines;

	vector<int> lines(num_lines);
	for (int i = 0; i < num_lines; i++) {
		cin >> lines[i];
	}

	cin >> num_huntings;

	vector<int> line_num(num_huntings);
	vector<int> bird_number(num_huntings);
	for (int i = 0; i < num_huntings; i++) {
		cin >> line_num[i];
		cin >> bird_number[i];
	}

	

	for (int i = 0; i < num_huntings; i++) {
		
		int line_number = line_num[i] - 1;
		int bird_num = bird_number[i];

		if (line_number == 0 || line_number == num_lines - 1) {
			// edge lines, the birds will fly away
			if (line_number == 0) {
				lines[line_number + 1] += lines[line_number] - bird_num;
				lines[line_number] = 0;
			}
			else if (line_number == num_lines - 1) {
				lines[line_number - 1] += bird_num - 1;
				lines[line_number] = 0;
			}
		}
		else {
			lines[line_number - 1] += bird_num - 1;
			lines[line_number + 1] += lines[line_number] - bird_num;
			lines[line_number] = 0;
		}
	}

	
	for (int i = 0; i < num_lines; i++) {
		cout << lines[i] << endl;
	}
	


	return 0;
}