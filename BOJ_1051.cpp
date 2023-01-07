#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	int k = 1;
	int result = 1;
	int counter = 0;
	int arr[51][51] = { 0 };
	string input;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			arr[i][j] = input[j]-'0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			counter = 0;
			for (int k = 1;; k++) {
				if ((j + k) >= m || (i + k) >= n) break;
				if (arr[i][j] == arr[i][j + k] && arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i + k][j + k]) // square
				{
					if (counter < k) { // update counter
						counter = k;
					}
				}
			}
			if ((counter + 1) > result) {
				result = counter + 1;
			}
		}
	}
	cout << result * result;
}