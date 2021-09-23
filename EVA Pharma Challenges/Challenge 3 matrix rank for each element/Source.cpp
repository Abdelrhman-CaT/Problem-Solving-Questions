#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

//vector<vector<double>> elements;

class element {
public:
	int row;
	int col;
	double val;
	int rank;
	element() {
		row = 0;
		col = 0;
		val = 0;
		rank = 1;
	}
	element(double val, int row, int col) {
		this->row = row;
		this->val = val;
		this->col = col;
		rank = 1;
	}
};


vector<element> sort(vector<element> mat) {
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat.size() - 1; j++) {
			if (mat[j].val > mat[j + 1].val) {
				element temp = mat[j];
				mat[j] = mat[j + 1];
				mat[j + 1] = temp;
			}
		}
	}

	return mat;
}


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
	vector<element> matrix(rows * cols);
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
					element tempelem = element(t, i, current_col);
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


void ranks(vector<element>& elems) {
	for (int i = 0; i < elems.size(); i++) {
		element current = elems[i];
		for (int j = 0; j < elems.size(); j++) {
			if (elems[j].row == current.row || elems[j].col == current.col) {
				if (elems[j].val > current.val) {
					if (elems[j].rank < current.rank + 1) {
						elems[j].rank = current.rank + 1;
					}
				}
			}
		}
	}
}

void parse_output(vector<vector<double>> answer, int rows, int cols) {
	if (rows > 1) {
		cout << "[";
	}
	for (int i = 0; i < rows; i++) {
		cout << "[";
		for (int j = 0; j < cols; j++) {
			cout << answer[i][j];
			if (j != cols - 1) {
				cout << ',';
			}
		}
		cout << ']';
		if (rows > 1 && i != rows - 1) {
			cout << ',';
		}
	}
	if (rows > 1) {
		cout << "]";
	}
}

int main() {
	string m;
	cin >> m;
	int rows = num_rows(m);
	int cols = num_cols(m);

	vector<element> matrix;
	vector<vector<double>> answer(rows, vector<double>(cols));
	
	// convert string input to vector
	matrix = parse_input(m);

	// matrix elements sorted by value
	vector<element> elements = sort(matrix);
	
	ranks(elements);
	
	for (int i = 0; i < rows * cols; i++) {
		int row = elements[i].row;
		int col = elements[i].col;
		int rank = elements[i].rank;
		answer[row][col] = rank;
	}


	parse_output(answer, rows, cols);
	
	

	return 0;
}