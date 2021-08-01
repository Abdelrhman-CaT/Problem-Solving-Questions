#include "iostream"
#include "cstdlib"
using namespace std;

int main() {

	int mat[5][5], row = 0, column = 0, moves = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 1) {
				row = i;
				column = j;
			}
		}
	}

	moves = abs(row - 2) + abs(column - 2);

	cout << moves;

	return 0;
}