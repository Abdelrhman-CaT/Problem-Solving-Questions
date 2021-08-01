#include "iostream"
#include "stdio.h"
#include "cmath"
using namespace std;

int main() {
	string n;
	cin >> n;
	
	unsigned long long sum = 0;
	unsigned long long power_val;

	for (int i = 0; i < n.length(); i++) {
		if (n[i] == '1') {
			power_val = 1;
			for (int j = 0; j < n.length()-1-i; j++) {
				power_val *= 2;
			}
			sum += 1 * power_val;
		}
	}

	cout << sum;
	return 0;
}