#include<iostream>
#include<vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	string x;
	cin >> x;

	int num_removed = 0;
	
	int i = 1;
	while (i < x.length()) {
		if (x[i] == x[i - 1]) {
			x.erase(x.begin()+i);
			i = i - 1;
			num_removed += 1;
		}
		i++;
	}

	
	cout << num_removed;

	return 0;
}

/*
#include<iostream>
#include<vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	string x;
	cin >> x;
	int num_removed = 0;
	int l = n;
	vector<bool> erased(l, false);
	for (int i = 1; i < l; i++) {
		if (x[i] == x[i - 1] && erased[i-1] == false) {
			erased[i] = true;
			num_removed += 1;
		}
		else if (erased[i - 1] == true) {
			int j = i - 1;
			while (erased[j] == true) {
				j--;
			}
			if (x[i] == x[j]) {
				erased[i] = true;
				num_removed += 1;
			}
		}
	}

	cout << num_removed;

	return 0;
}
*/