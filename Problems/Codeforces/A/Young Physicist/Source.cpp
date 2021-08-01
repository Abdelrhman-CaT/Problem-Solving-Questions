#include "iostream"
using namespace std;

int main() {
	int vects[100][3], n, x=0, y=0, z=0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> vects[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		x += vects[i][0];
		y += vects[i][1];
		z += vects[i][2];
	}

	if ((x == 0) && (y == 0) && (z == 0)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}