#include<iostream>
#include<vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	int num_groups = 0;
	vector<string> magnets(n);
	for (int i = 0; i < n; i++) {
		cin >> magnets[i];
	}

	
	if (n == 1) {
		num_groups = 1;
	}
	else {
		int i = 1;
		while (i < n) {
			char prev;
			char curr;
			prev = magnets[i - 1][1];
			curr = magnets[i][0];
			if (prev == curr) {
				num_groups += 1;
			}
			i++;
		}
		num_groups += 1;
	}
	//
	
	cout << num_groups;

	return 0;
}