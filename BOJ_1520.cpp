#include <bits/stdc++.h>
using namespace std;

int m, n, ret;
int a[501][501], dp[501][501];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

int solve(int row, int col) {
	if (row == m - 1 && col == n - 1) {
		return 1;
	}
	if (dp[row][col] == -1) {
		dp[row][col] = 0;
		for (int i = 0; i < 4; i++) {
			int nRow = row + dx[i];
			int nCol = col + dy[i];
			if (nRow < 0 || nCol < 0 || nRow >= m || nCol >= n) continue;
			if (a[nRow][nCol] != 0 && a[row][col] > a[nRow][nCol]) dp[row][col] += solve(nRow, nCol);
		}
	}
	return dp[row][col];
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << "\n";
	return 0;
}