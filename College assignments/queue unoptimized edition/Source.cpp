#include <iostream>
using namespace std;

float maxArray(float arr[], int start, int end) {
	if (start == end) {
		return arr[start];
	}

	int middle = (start + end) / 2;
	float maax1 = maxArray(arr, start, middle);
	float maax2 = maxArray(arr, middle + 1, end);

	if (maax1 >= maax2) {
		return maax1;
	}
	else {
		return maax2;
	}
}

float minArray(float arr[], int start, int end) {
	if (start == end) {
		return arr[start];
	}
	
	int middle = (start + end) / 2;
	float miin1 = minArray(arr, start, middle);
	float miin2 = minArray(arr, middle + 1, end);

	float min;
	if (miin1 <= miin2) {
		return miin1;
	}
	else {
		return miin2;
	}
}


int main() {

	int m, n, min_index;
	float min_element, waiting_Time = 0, max_time;
	cin >> m >> n;

	float* processes = new float[n];
	float* server = new float[m];
	float* turnaround = new float[n];
	float* waiting = new float[n];
	
	for (int k = 0; k < n; k++) {
		cin >> processes[k];
	}

	for (int k = 0; k < m; k++) {
		server[k] = 0;
	}

	for (int k = 0; k < n; k++) {
		min_element = minArray(server, 0, m - 1);
		for (int j = 0; j < n; j++) {
			if (server[j] == min_element) {
				min_index = j;
				break;
			}
		}
		server[min_index] += processes[k];
		turnaround[k] = server[min_index];
	}

	max_time = maxArray(turnaround, 0, n - 1);

	for (int k = 0; k < n; k++) {
		waiting[k] = turnaround[k] - processes[k];
		waiting_Time = waiting_Time + waiting[k];
	}

	waiting_Time = waiting_Time / n;
	

	cout << max_time << " ";
	cout << waiting_Time;

	delete[] processes;
	delete[] server;
	delete[] turnaround;
	delete[] waiting;

	return 0;
}