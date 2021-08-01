#include "iostream"
using namespace std;

int main() {
	int yakko, wakko;
	cin >> yakko >> wakko;

	int max;
	if (yakko >= wakko) {
		max = yakko;
	}
	else {
		max = wakko;
	}

	int num = 6 - max + 1;
	int den = 6;
	int by3 = 0;
	int by2 = 0;

	while (true){
		if (num % 2 == 0 && num != 0) {
			by2 += 1;
			num /= 2;
			if (by2 == 1 && num != 3) {
				break;
			}
		}
		else if(num % 3 == 0 && num != 0){
			by3 += 1;
			num /= 3;
		}
		else {
			break;
		}
	}
	
	if (!(by2 == 0 && by3 == 0)) {
		den = 6 / (2 * by2 + 3 * by3);
	}

	cout << num << '/' << den;
	

	return 0;
}