#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int arr[52][52], temp[52][52];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
vector<int> v;
int dustSum = 0;

void spread() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int cnt = 0;
			int dNum = 0;
			if (arr[i][j] > 0) {
				dNum = arr[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
					if (arr[ny][nx] == -1) continue;
					temp[ny][nx] += dNum;
					cnt++;
				}
			}
			arr[i][j] -= dNum * cnt;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] += temp[i][j];
		}
	}
}

void purify() {
	int firstP = v[0];
	int secondP = v[1];
	dustSum -= (arr[firstP - 1][0] + arr[secondP + 1][0]);

	int firstRight = arr[firstP][c - 1];
	int secondRight = arr[secondP][c - 1];
	for (int i = c - 1; i >= 2; i--) { // ->
		arr[firstP][i] = arr[firstP][i - 1];
		arr[secondP][i] = arr[secondP][i - 1];
	}

	int firstLeft = arr[0][0];
	int secondLeft = arr[r - 1][0];
	for (int i = 0; i < c; i++) { // <-
		arr[0][i] = arr[0][i + 1];
		arr[r - 1][i] = arr[r - 1][i + 1];
	}

	for (int i = firstP - 1; i >= 1; i--) {
		arr[i][0] = arr[i - 1][0];
	}
	for (int i = 0; i < firstP - 1; i++) {
		arr[i][c - 1] = arr[i + 1][c - 1];
	}
	for (int i = r - 1; i > secondP + 1; i--) {
		arr[i][c - 1] = arr[i - 1][c - 1];
	}
	for (int i = secondP + 1; i < r - 1; i++) {
		arr[i][0] = arr[i + 1][0];
	}
	arr[firstP - 1][c - 1] = firstRight;
	arr[secondP + 1][c - 1] = secondRight;
	arr[1][0] = firstLeft;
	arr[r - 2][0] = secondLeft;
	arr[firstP][1] = 0;
	arr[secondP][1] = 0;
}

int main() {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0) {
				dustSum += arr[i][j];
			}
			if (arr[i][j] == -1) v.push_back(i);
		}
	}
	while (t--) {
		memset(temp, 0, sizeof(temp));
		spread();
		purify();
	}
	cout << dustSum << "\n";
	return 0;
}