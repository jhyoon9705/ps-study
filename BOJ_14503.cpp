#include <bits/stdc++.h>
using namespace std;

int r, c, d, n, m, ret;
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };
int arr[52][52], visited[52][52];
int robot_r, robot_c, robot_d;

void solve(int row, int col, int dir) {
	if (visited[row][col] == 0) {
		visited[row][col] = 1;
		ret++;
	}
	for (int i = 0; i < 4; i++) {
		int nDir = (dir + 3 - i) % 4;
		int nRow = row + dy[nDir];
		int nCol = col + dx[nDir];
		if (nRow < 0 || nCol < 0 || nRow >= n || nCol >= m || visited[nRow][nCol] == 1) continue;
		if (arr[nRow][nCol] != 1) {
			solve(nRow, nCol, nDir);
		}
	}
	int b_row = row + dy[(dir + 2) % 4];
	int b_col = col + dx[(dir + 2) % 4];
	if (b_row >= 0 && b_row < n && b_col >= 0 && b_col < m && arr[b_row][b_col] != 1) {
		solve(b_row, b_col, dir);
	}
	else {
		cout << ret << "\n";
		exit(0);
	}
}

int main() {
	cin >> n >> m;
	cin >> robot_r >> robot_c >> robot_d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	solve(robot_r, robot_c, robot_d);
	return 0;
}