#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;


int main() {

	int mmm;
	cin >> mmm;
	int nnn;
	cin >> nnn;

	vector<double> requests(nnn);
	vector<double> servers(mmm);
	vector<double> entry(nnn);  // waiting
	vector<double> exit(nnn);   // turnaround

	int count0 = nnn;
	while (count0 > 0) {
		cin >> requests[nnn - count0];
		count0 -= 1;
	}
	

	int least;
	int count1 = nnn;
	while (count1 > 0) {
		least = min_element(servers.begin(), servers.end()) - servers.begin(); // get the index of the element with the minimum value
		servers[least] += requests[nnn - count1];
		exit[nnn - count1] = servers[least];
		count1 -= 1;
	}
	
	cout << *(max_element(exit.begin(), exit.end())) << " ";   // prints the value of the max element in turnaround

	int count2 = nnn;
	while (count2 > 0) {
		entry[nnn - count2] = exit[nnn - count2] - requests[nnn - count2];
		count2 -= 1;
	}
	
	int count3 = nnn;
	double s = 0;
	while (count3 > 0) {
		s += entry[nnn - count3];
		count3 -= 1;
	}
	
	cout << s / nnn;
	
	return 0;
}