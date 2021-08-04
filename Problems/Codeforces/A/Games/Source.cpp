#include<iostream>
#include<vector>
using namespace std;


int main() {
	int n;
	int num = 0;
	cin >> n;
	vector<vector<int>>teams(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			int temp;
			cin >> temp;
			teams[i].push_back(temp);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (teams[i][0] == teams[j][1]) {
					num += 1;
				}
			}
		}
	}

	cout << num;

	return 0;
}