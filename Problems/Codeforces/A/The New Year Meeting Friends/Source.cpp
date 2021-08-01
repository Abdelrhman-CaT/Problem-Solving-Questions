#include "iostream"
#include "cstdlib"
using namespace std;

int main() {
	int x1, x2, x3, inter=0, dist=0;
	cin >> x1 >> x2 >> x3;
	
	if ((x1 > x2 && x1 < x3) || (x1 > x3 && x1 < x2)) {
		inter = x1;
	}
	else if ((x2 > x1 && x2 < x3) || (x2 > x3 && x2 < x1)) {
		inter = x2;
	}
	else {
		inter = x3;
	}

	dist = abs(x1-inter) + abs(x2-inter) + abs(x3-inter);

	cout << dist;
	
	return 0;
}