#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, temp, number;
	int input;
	int emptyCount;
	cin >> n;

	vector<int> v, result;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
		result.push_back(0); // replace empty space to zero
	}

	for (int j = 0; j < n; j++) {
		number = j + 1;
		temp = v[j]; // the number of numbers on the left that are bigger than itself
		k = 0;
		emptyCount = 0;

		// Starting from the left, assign empty space as much as 'temp' variable
		while (temp != emptyCount) {
			if (result[k] == 0) {
				emptyCount++;
			}
			k++;
		}

		while (result[k] != 0) { // find empty space
			k++;
		}
		result[k] = number;
	}

	for (int l = 0; l < n; l++) {
		cout << result[l] << " ";
	}
}