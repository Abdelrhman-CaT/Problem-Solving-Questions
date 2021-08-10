#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int i;
	int first_match = 0;
	int last_match = 0;
	int res = 0;
	cin >> n;

	vector<long long> stewards(n);
	for (int i = 0; i < n; i++) {
		cin >> stewards[i];
	}

	sort(stewards.begin(), stewards.end());

	i = 0;
	while (i < stewards.size() && stewards[i] == stewards[0]) {
		first_match += 1;
		i++;
	}

	i = stewards.size() - 1;
	while (i >= 0 && stewards[i] == stewards[stewards.size() - 1]) {
		last_match += 1;
		i--;
	}


	for (int i = first_match; i < stewards.size() - last_match; i++) {
		res += 1;
	}

	cout << res;

	return 0;
}