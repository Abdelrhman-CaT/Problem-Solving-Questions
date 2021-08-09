#include<iostream>
#include<vector>
using namespace std;

vector<bool> snacks(100001, false);
int largest;

void out(int temp) {
	while (temp == largest && snacks[largest] == true) {
		cout << largest  << " ";
		largest -= 1;
		temp -= 1;
	}

	cout << endl;
}

int main() {
	int n;
	cin >> n;

	largest = n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		snacks[temp] = true;
		out(temp);
	}

	return 0;
}



// The code below causes TIME LIMIT EXCEEDED
/*
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

void insert_waiting(int num, list<int> &waiting) {
	waiting.push_back(num);
	waiting.sort();
}

int get_element(list<int> waiting, int j) {
	list<int>::iterator ret = waiting.begin();
	for (int i = 0; i < j; i++) {
		ret++;
	}
	return *ret;
}

int main() {
	int n;
	int prev;
	int printed_from_waiting;
	int j;
	cin >> n;

	int largest = n;

	vector<int> snacks(n);
	list<int> waiting;

	for (int i = 0; i < n; i++) {
		cin >> snacks[i];
	}

	for (int i = 0; i < n; i++) {
		if (snacks[i] == largest) {
			cout << snacks[i];
			if (waiting.size() > 0) {
				printed_from_waiting = 0;
				prev = snacks[i];
				j = waiting.size() - 1;
				int curr = get_element(waiting, j);
				while (j >= 0 && prev -  curr == 1) {
					cout << " ";
					cout << curr;
					prev = curr;
					printed_from_waiting += 1;
					j--;
					if (j >= 0) {
						curr = get_element(waiting, j);
					}
				}
				if (printed_from_waiting > 0) {
					list<int>::iterator b = waiting.end();
					for (int k = 0; k < printed_from_waiting; k++) {
						b--;
					}
					//waiting.erase(waiting.begin(), waiting.end());
					largest = get_element(waiting, waiting.size() - printed_from_waiting);
				}
			}
			largest -= 1;
			if (i != n - 1) {
				cout << endl;
			}
		}
		else {
			cout << endl;
			insert_waiting(snacks[i], waiting);
		}
	}


	return 0;
}
*/