#include <iostream>
using namespace std;

int main() {
	int k, r;
	cin >> k;
	cin >> r;
	int price = k;
	int num_shovels = 1;
	
	while(true){
		if (k % 10 == 0) {
			break;
		}
		else {
			if ((k - r) % 10 == 0) {
				break;
			}
			else {
				num_shovels += 1;
				k = price * num_shovels;
			}
		}
	}


	cout << num_shovels;

	return 0;
}