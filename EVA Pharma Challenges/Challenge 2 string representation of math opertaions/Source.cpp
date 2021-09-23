#include <iostream>
#include <stack>
#include <string>
using namespace std;

string remove_terminal_spaces(string s) {
	string res = "";
	for (int i = 0; i < s.length(); i++) {
		if (i == 0) {
			if (s[i] != ' ') {
				res += s[i];
			}
		}
		else if (i == s.length() - 1) {
			if (s[i] != ' ') {
				res += s[i];
			}
		}
		else if (i != 0 || i != s.length() - 1) {
			res += s[i];
		}
	}

	return res;
}


bool is_number(char x) {
	if (x >= 48 && x <= 57 ) {
		return true;
	}
	else {
		return false;
	}
}

string infix2postfix(string str) {
	stack<char> operators;
	string res = "";
	for (int i = 0; i < str.length(); i++) {
		if (is_number(str[i]) || str[i] == ' ') {
			if (str[i] == ' ' && res[res.length() - 1] != ' ') {
				res += str[i];
			}
			else if (str[i] != ' ') {
				res += str[i];
			}
			
		}
		else {
			if (res.length() > 0) {
				if (res[res.length() - 1] != ' ') {
					res += ' ';
				}
			}
			if (str[i] == ')') {
				while (operators.top() != '(') {
					if (res[res.length() - 1] != ' ') {
						res += ' ';
					}
					res += operators.top();
					operators.pop();
				}
				operators.pop();
			}
			else {
				if (operators.empty()) {
					operators.push(str[i]);
				}
				else {
					if (str[i] == '(') {
						operators.push(str[i]);
					}
					else {
						if (res[res.length() - 1] != ' ') {
							res += ' ';
						}
						if (operators.top() != '(') {
							res += operators.top();
							res += ' ';
							operators.pop();
						}
						operators.push(str[i]);
					}			
				}
			}
		}
	}
	while (operators.empty() == 0) {
		res += ' ';
		res += operators.top();
		operators.pop();
	}
	return res;
}



float eval(float num1, float num2, char op) {
	if (op == '+') {
		return num1 + num2;
	}
	else if (op == '-') {
		return num1 - num2;
	}
}

// postfix evaluation example
float postfix_eval(string str) {
	stack<double> nums;
	string temp = "";
	for (int i = 0; i < str.length(); i++) {
		if (is_number(str[i]) || str[i] == ' ') {
			if (str[i] != ' ') {
				temp += str[i];
			}
			else {
				if (temp != "") {
					nums.push(stof(temp));
					temp = "";
				}
			}
		}
		else {
			double num1 = nums.top();
			double num2;
			nums.pop();
			if (nums.empty()) {
				num2 = 0;
			}
			else {
				num2 = nums.top();
				nums.pop();
			}

			nums.push(eval(num2, num1, str[i]));
		}
	}
	return nums.top();
}




int main() {
	// Idea: convert infix to postix then evaluate postfix
	string s, clean_s, postfix;
	getline(cin, s);
	clean_s = remove_terminal_spaces(s);
	postfix = infix2postfix(clean_s);
	cout << postfix_eval(postfix);

	return 0;
}