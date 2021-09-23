#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class element {
public:
	int row;
	int col;
	double val;
	element() {
		row = 0;
		col = 0;
		val = 0;
	}
	element(double val, int row, int col) {
		this->row = row;
		this->val = val;
		this->col = col;
	}

	element move_down(vector<element>m) {
		int new_row = this->row + 1;
		int col = this->col;
		element retVal;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].row == new_row && m[i].col == col) {
				retVal = m[i];
				break;
			}
		}
		return retVal;
	}

	element move_right(vector<element>m) {
		int row = this->row;
		int new_col = this->col + 1;
		element retVal;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].row == row && m[i].col == new_col) {
				retVal = m[i];
				break;
			}
		}
		return retVal;
	}
};


int num_rows(string mat) {
	int c = 0;
	for (int i = 0; i < mat.length(); i++) {
		if (mat[i] == '[') {
			c += 1;
		}
	}

	if (c == 1) {
		return c;
	}
	else {
		return c - 1;
	}
}

int num_cols(string mat) {
	int end_row = mat.find(']') - 1;
	int start_row;
	int count = 1;
	if (num_rows(mat) == 1) {
		start_row = 1;
	}
	else {
		start_row = 2;
	}
	for (int i = start_row; i <= end_row; i++) {
		if (mat[i] == ',') {
			count += 1;
		}
	}
	return count;
}


vector<element> parse_input(string m) {
	int rows = num_rows(m);
	int cols = num_cols(m);
	vector<element> matrix(rows*cols);
	int i = 0;
	int current_col = 0;
	int j = 0;
	int vector_index = 0;
	bool row_separator = false;
	while (i < rows) {
		current_col = 0;
		while (m[j] != ']') {
			if (m[j] != '[') {
				if (m[j] != ',') {
					string temp = "";
					while (m[j] != ',' && m[j] != ']') {
						temp += m[j];
						j++;
					}
					j--;
					//cout << temp << endl;
					double t;
					t = stof(temp);
					element tempelem = element(t,i,current_col);
					matrix[vector_index] = tempelem;
					vector_index += 1;
				}
				else if (m[j] == ',' && !row_separator) {
					current_col += 1;
				}
				else {
					row_separator = false;
				}
			}
			j++;
		}
		j++;
		i++;
		row_separator = true;
	}
	return matrix;
}


void adjust_health(double* h, double* stash, element t) {
	double temp = *h;
	if (temp - t.val <= 1) {
		*stash += t.val;
	}
	else {
		if (*stash > 0) {
			if (*stash >= abs(t.val)) {
				*stash -= t.val;
			}
			else {
				double diff = abs(t.val) - *stash;
				*stash = 0;
				*h += diff;
			}
		}
		else {
			*h -= t.val;
		}
	}
}


void calc_health(element t, int rows, int cols, vector<element> m, double *health, double* stash) {
	if (t.row + 1 >= rows && t.col + 1 >= cols) {
		return;
	}

	if (t.row + 1 < rows && t.col + 1 >= cols) {
		element t1 = t.move_down(m);
		adjust_health(health, stash, t1);
		return calc_health(t1, rows, cols, m, health, stash);
	}

	if (t.row + 1 >= rows && t.col + 1 < cols) {
		element t1 = t.move_right(m);
		adjust_health(health, stash, t1);
		return calc_health(t1, rows, cols, m, health, stash);
	}

	if (t.row + 1 < rows && t.col + 1 < cols) {
		element t1 = t.move_right(m);
		element t2 = t.move_down(m);
		element t3;
		if (t1.val > t2.val) {
			t3 = t1;
		}
		else if (t1.val < t2.val) {
			t3 = t2;
		}
		else if (t1.val == t2.val) {
			double h1 = *health;
			adjust_health(&h1, stash, t1);
			double h2 = *health;
			adjust_health(&h2, stash, t1);
			double stash1 = *stash;
			double stash2 = *stash;
			calc_health(t1, rows, cols, m, &h1, &stash1);
			calc_health(t2, rows, cols, m, &h2, &stash2);
			if (h1 < h2) {
				*health = h1;
				return;
			}
			else {
				*health = h2;
				return;
			}
		}
		adjust_health(health, stash, t3);
		return calc_health(t3, rows, cols, m, health, stash);
	}
}


int main() {
	string m;
	cin >> m;
	double health = 1;
	int rows = num_rows(m);
	int cols = num_cols(m);

	vector<element> dungeon;

	// convert string input to vector
	dungeon = parse_input(m);

	health -= dungeon[0].val;
	double stash = 0;
	calc_health(dungeon[0],rows, cols, dungeon, &health, &stash);

	if (health <= 0) {
		health = 1;
	}

	cout << "Minimum Health is: " << health << " HP";

	return 0;
}