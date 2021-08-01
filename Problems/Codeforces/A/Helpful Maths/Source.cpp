#include "iostream"
using namespace std;

int main() {
	string op;
	cin >> op;
	string form = "";
	char tmp;
	
	for (int i = 0; i < op.length(); i += 2) {
		form += op[i];
	}

	for (int i = 0; i < form.length(); i++) {
		for (int j = 0; j < form.length(); j++) {
			if (form[i] < form[j]) {
				tmp = form[i];
				form[i] = form[j];
				form[j] = tmp;
			}
		}
	}

	for (int i=0; i < op.length(); i+=2) {
		op[i] = form[i/2];
	}
	cout << op;

	return 0;
}