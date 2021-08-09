#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	int n;
	long long sum = 0;
	cin >> n;

	vector<long long> cities(n);
	for (int i = 0; i < n; i++) {
		cin >> cities[i];
		sum += abs(cities[i]);
	}

	vector<long long> min(n, sum);
	vector<long long> max(n, 0);
	vector<vector<int>> adj(n);


	for (int i = 0; i < n; i++) {
		if (i == 0) {
			adj[i].push_back(i + 1);
		}
		else if (i == n - 1) {
			adj[i].push_back(i - 1);
		}
		else {
			adj[i].push_back(i + 1);
			adj[i].push_back(i - 1);
		}
	}

	for (int i = 0; i < n; i++) {
		int from_begining = abs(cities[i] - cities[0]);
		int from_end = abs(cities[i] - cities[n - 1]);
		max[i] = (from_begining > from_end) ? from_begining : from_end;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			int diff = abs(cities[i] - cities[adj[i][j]]);
			if (diff < min[i]) {
				min[i] = diff;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		cout << min[i] << " " << max[i];
		if (i != n - 1) {
			cout << endl;
		}
	}

	return 0;
}