#include <iostream>
#include <vector>
using namespace std;

bool exists(vector<int> x, int y) {
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == y) {
			return true;
		}
	}
	return false;
}



int main() {
	int n;
	cin >> n;

	vector<bool> marked(n, false);
	vector<vector<int>> teams(n);
	vector<vector<int>> res(n);
	int vector_index = 0;
	int full_index = -1;

	// output vars
	int num_teams = 0;

	vector<int> students(n);
	for (int i = 0; i < n; i++) {
		cin >> students[i];
	}


	for (int i = 0; i < n; i++) {
		vector_index = full_index + 1;

		while (marked[i] == false) {
			if (exists(teams[vector_index], students[i]) == false) {
				teams[vector_index].push_back(students[i]);
				res[vector_index].push_back(i + 1);
				marked[i] = true;
			}
			else {
				vector_index += 1;
			}
		}

		if (res[vector_index].size() == 3) {
			full_index = vector_index;
		}
	}


	// output phase
	for (int i = 0; i < res.size(); i++) {
		if (res[i].size() == 3) {
			num_teams += 1;
		}
	}

	cout << num_teams;


	if (num_teams != 0) {
		cout << endl;
		for (int i = 0; i < num_teams; i++) {
			for (int j = 0; j < res[i].size(); j++) {
				cout << res[i][j];
				if (j != res[i].size() - 1) {
					cout << " ";
				}
			}
			if (i != num_teams - 1) {
				cout << endl;
			}
		}

	}

	return 0;
}