#include <iostream>
#include <cassert>

#define MAX_SIZE 1000

using namespace std;

template<class F>
class stack {
private:
	F arr[MAX_SIZE];
	int size;
public:
	stack() {
		size = 0;
	}

	void push(F data) {
		assert(size < MAX_SIZE);
		arr[size] = data;
		size += 1;
	}

	void pop() {
		assert(size > 0);
		size -= 1;
	}

	F top() {
		assert(size > 0);
		return arr[size - 1];
	}

	int get_size() {
		return size;
	}

	bool is_empty() {
		return (size == 0);
	}

	bool is_full() {
		return (size == MAX_SIZE);
	}
};


bool is_opening(char x) {
	if (x == '(' || x == '<' || x == '{' || x == '[') {
		return true;
	}
	else {
		return false;
	}
}

bool matching(char x, char y) {
	if (x == '<' && y == '>') {
		return true;
	}
	else if (x == '(' && y == ')') {
		return true;
	}
	else if (x == '[' && y == ']') {
		return true;
	}
	else if (x == '{' && y == '}') {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n;
	int no_stack_check;
	cin >> n;
	string* arr;

	if (n <= -1 || n > 1000 || n == 0) {
		cout << "NO";
		return 0;
	}

	arr = new string[n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		no_stack_check = 0;
		stack<char> tag;
		string line = arr[i];
		int l = line.length();

		for (int j = 0; j < l; j++) {
			if (is_opening(line[j])) {
				tag.push(line[j]);
			}
			else {
				if (tag.is_empty()) {
					no_stack_check = 1;
					cout << "NO";
					break;
				}
				else {
					if (!matching(tag.top(), line[j])) {
						cout << "NO";
						no_stack_check = 1;
						break;
					}
					else {
						tag.pop();
					}
				}
			}
		}

		if (!no_stack_check) {
			if (tag.is_empty()) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
		}

		if (i != n - 1) {
			cout << endl;
		}
	}

	delete[]arr;
	return 0;
}