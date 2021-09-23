#include <iostream>
#include <vector>


using namespace std;

class element {
public:
	int row;
	int col;
	char val;
	int num_affected;

	element() {
		row = 0;
		col = 0;
		val = 0;
		num_affected = 0;
	}

	element(char val, int row, int col) {
		this->row = row;
		this->val = val;
		this->col = col;
		num_affected = 0;
	}

	element* get_right(vector<element> *x) {
		vector<element> m = *x;
		int row = this->row;
		int col = this->col + 1;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].row == row && m[i].col == col) {
				return &(*(x->begin()+i));
			}
		}
	}

	element* get_left(vector<element> *x) {
		vector<element> m = *x;
		int row = this->row;
		int col = this->col - 1;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].row == row && m[i].col == col) {
				return &(*(x->begin() + i));
			}
		}
	}

	element* get_upper_right(vector<element> *x) {
		vector<element> m = *x;
		int row = this->row - 1;
		int col = this->col + 1;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].row == row && m[i].col == col) {
				return &(*(x->begin() + i));
			}
		}
	}

	element* get_upper_left(vector<element> *x) {
		vector<element> m = *x;
		int row = this->row - 1;
		int col = this->col - 1;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].row == row && m[i].col == col) {
				return &(*(x->begin() + i));
			}
		}
	}

	element* get_lower_left(vector<element> *x) {
		vector<element> m = *x;
		int row = this->row + 1;
		int col = this->col - 1;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].row == row && m[i].col == col) {
				return &(*(x->begin() + i));
			}
		}
	}

	element* get_lower_right(vector<element> *x) {
		vector<element> m = *x;
		int row = this->row + 1;
		int col = this->col + 1;
		for (int i = 0; i < m.size(); i++) {
			if (m[i].row == row && m[i].col == col) {
				return &(*(x->begin() + i));
			}
		}
	}

	vector<element*> get_surroundings(vector<element> *x, int rows, int cols) {
		vector<element*> surr;
		if (this->row > 0) {
			if (this->col > 0) {
				surr.push_back(this->get_upper_left(x));
			}
			if (this->col < cols - 1) {
				surr.push_back(this->get_upper_right(x));
			}
		}
		if (this->col > 0) {
			surr.push_back(this->get_left(x));
		}
		if (this->col < cols - 1) {
			surr.push_back(this->get_right(x));
		}
		return surr;
	}


	vector<element*> get_affected(vector<element>* m, int rows, int cols) {
		vector<element*> surr;
		if (this->row < rows - 1) {
			if (this->col > 0) {
				element* temp = this->get_lower_left(m);
				if (temp->val == 'x' || temp->val == '.') {
					surr.push_back(temp);
				}
			}
			if (this->col < cols - 1) {
				element *temp = this->get_lower_right(m);
				if (temp->val == 'x' || temp->val == '.') {
					surr.push_back(temp);
				}
			}
		}
		if (this->col > 0) {
			element *temp = this->get_left(m);
			if (temp->val == 'x' || temp->val == '.') {
				surr.push_back(temp);
			}
		}
		if (this->col < cols - 1) {
			element *temp = this->get_right(m);
			if (temp->val == 'x' || temp->val == '.') {
				surr.push_back(temp);
			}
		}
		return surr;
	}

	int get_num_affected(vector<element> *m, int rows, int cols) {
		int num = 0;
		if (this->row < rows - 1) {
			if (this->col > 0) {
				element *temp = this->get_lower_left(m);
				if (temp->val == 'x' || temp->val == '.') {
					num += 1;
				}
			}
			if (this->col < cols - 1) {
				element *temp = this->get_lower_right(m);
				if (temp->val == 'x' || temp->val == '.') {
					num += 1;
				}
			}
		}
		if (this->col > 0) {
			element *temp = this->get_left(m);
			if (temp->val == 'x' || temp->val == '.') {
				num += 1;
			}
		}
		if (this->col < cols - 1) {
			element *temp = this->get_right(m);
			if (temp->val == 'x' || temp->val == '.') {
				num += 1;
			}
		}
		return num;
	}

	
	bool is_broken() {
		if (this->val == '#') {
			return true;
		}
		else {
			return false;
		}
	}

	bool has_student() {
		if (this->val == 's') {
			return true;
		}
		else {
			return false;
		}
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
					element tempelem = element(m[j], i, current_col);
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

bool has_x(vector<element*>p) {
	for (int i = 0; i < p.size(); i++) {
		if (p[i]->val == 'x') {
			return true;
		}
	}
	return false;
}

int num_students(vector<element> m, int rows, int cols) {
	int num = 0;
	bool student_in_surr;
	bool potential_surr_seat;
	vector<element*> potential;

	for (int i = 0; i < m.size(); i++) {
		student_in_surr = false;
		potential_surr_seat = false;
		element curr = m[i];

		if (!curr.is_broken()) {
			vector<element*> surroundings = curr.get_surroundings(&m, rows, cols);
			for (int j = 0; j < surroundings.size(); j++) {
				element curr_surr = *surroundings[j];
				if (curr_surr.has_student()) {
					student_in_surr = true;
					break;
				}
				if (curr_surr.val == '.' || curr_surr.val == 'x') {
					potential_surr_seat = true;
				}
			}
			if (student_in_surr == true) {
				m[i].val = 'a';   // non-broken seat and there is a student sitting nearby
			}
			else if (potential_surr_seat == true) {
				m[i].val = 'x';  // non-broken seat and there is another non-broken seat nearby
				potential.push_back(&m[i]);
			}
			else {
				m[i].val = 's'; // non-broken seat and all its surroundings are broken
				num += 1;
			}
		}
	}

	// handle potential seats
	for (int i = 0; i < potential.size(); i++) {
		for (int j = 0; j < potential.size() - 1; j++) {
			if (potential[j]->get_num_affected(&m, rows, cols) > potential[j + 1]->get_num_affected(&m, rows, cols)) {
				element temp = *(potential[j]);
				*(potential[j]) = *(potential[j + 1]);
				*(potential[j + 1]) = temp;
			}
		}
	}
	int index = 0;
	while (has_x(potential)) {
		while(potential[index]->val == 'a' || potential[index]->val == 's') {
			index += 1;
		}
		potential[index]->val = 's';
		num += 1;
		vector<element*> aff = potential[index]->get_affected(&m, rows, cols);
		for (int j = 0; j < aff.size(); j++) {
			aff[j]->val = 'a';
		}
		
	}
	return num;
}


int main() {
	string m;
	cin >> m;
	int rows = num_rows(m);
	int cols = num_cols(m);
	int students;

	vector<element> matrix;
	matrix = parse_input(m);

	students = num_students(matrix, rows, cols);
	cout << students;

	return 0;
}