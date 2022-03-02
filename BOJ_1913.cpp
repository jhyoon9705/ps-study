#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, target;
	int targetX = 0;
	int targetY = 0;
	int i = 1;
	int j = 1;
	int direction = 1;
	
	cin >> n;
	cin >> target;

	int number = n * n;
		
	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));

	while (number) {

		if (target == number) {
			targetX = i;
			targetY = j;
		}

		v[i][j] = number;

		if (i == j && (n / 2 + 1) >= i) { // top left
			direction = 1; // to down
			i++;
		}
		else if (i == j && (n / 2 + 1) < i) { // bottom right
			direction = 2; // to up
			i--;
		}
		else if (i + j == n + 1 && i > j) { // left bottom
			direction = 3; // to right
			j++;
		}
		else if (i + j == n + 1 && i < j) { // top right
			direction = 4; // to left
			j--;
		}
		else if (j - i == 1 && i <= (n / 2) + 1 && j - 1 != (n / 2 + 1)) {
			i++;
		}
		else {
			switch (direction) {
			case 1:
				i++;
				break;
			case 2:
				i--;
				break;
			case 3:
				j++;
				break;
			case 4:
				j--;
				break;
			default:
				break;
			}

		}

		number--;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << v[i][j] << ' ';
		}
		cout << "\n";

	}
	cout << targetX << ' ' << targetY;

}