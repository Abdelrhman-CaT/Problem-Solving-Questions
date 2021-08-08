#include<iostream>
#include<math.h>
using namespace std;


int main() {
	float n, t, k, d;
	int time_oven1;
	int cakes_done_during_making_oven2;
	int time_oven2;
	cin >> n >> t >> k >> d;

	if (n < k) {
		cout << "NO";
	}
	else {
		time_oven1 = t * (ceil(n/k));
		cakes_done_during_making_oven2 = floor(d / t) * k;
		time_oven2 = d + (t) * (ceil((n - cakes_done_during_making_oven2) / (k * 2)));

		if (time_oven2 >= time_oven1) {
			cout << "NO";
		}
		else {
			cout << "YES";
		}
	}

		

	return 0;
}