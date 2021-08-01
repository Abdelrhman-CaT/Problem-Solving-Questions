#include <iostream>
#include <string> 
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int  main() {

	int n;
	cin >> n;

	map<string, int[2]> db; // index 0 works as repetition detector, index 1 works as repetition counter 
	vector<string> arr(n);
	vector<int> flag(n);
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	
	for (int i = 0; i < n; i++) {
		if (db.find(arr[i]) == db.end()) {
			db[arr[i]][0] = 0;	
		}
		else {
			db[arr[i]][0] = 1;
		}
		db[arr[i]][1] = 0;
	}

	for (int i = 0; i < n; i++) {
		if (db[arr[i]][0] == 0) {
			flag[i] = 0;
		}
		else if (db[arr[i]][0] != 0) {
			flag[i] = db[arr[i]][1];
			db[arr[i]][1] += 1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (flag[i] == 0) {
			arr[i] = "OK";
		}
		else {
			arr[i] = arr[i] + std::to_string(flag[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i];
		if (i != n - 1) {
			cout << endl;
		}
	}


	return 0;
}