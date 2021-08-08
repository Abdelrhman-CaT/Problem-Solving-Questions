#include <iostream>
#include <vector>
#include <iomanip>
#include<math.h>
using namespace std;

int main() {
	long long n, d;
	int num_distress = 0;

	cin >> n >> d;

	vector<char> giveOrTake(n);
	vector<long long> amount(n);

	for (int i = 0; i < n; i++) {
		cin >> giveOrTake[i];
		cin >> amount[i];
	}

	for (int i = 0; i < n; i++) {
		if (giveOrTake[i] == '+') {
			d += amount[i];
		}
		else {
			if (d >= amount[i]) {
				d -= amount[i];
			}
			else {
				num_distress += 1;
			}
		}
	}

	cout << d << " " << num_distress;


	return 0;
}