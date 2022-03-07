#include<bits/stdc++.h>

using namespace std;

int main() {
	int arr[100][2] = { 0 };
	int cow, location;
	int counter = 0;
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(-1);
	}

	for (int i = 0; i < n; i++) {
		cin >> cow >> location;
		arr[i][0] = cow;
		arr[i][1] = location;
	}

	for (int j = 0; j < n; j++) {
		if (v.at(arr[j][0]-1) == -1) {
			v[arr[j][0] - 1] = arr[j][1];
		}
		else if (v.at(arr[j][0] - 1) != arr[j][1]) {
			counter++;
			v[arr[j][0] - 1] = arr[j][1];
		}
	}

	cout << counter;
}