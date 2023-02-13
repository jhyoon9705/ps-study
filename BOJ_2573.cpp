#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int ice[301][301], visited[301][301], temp[301][301];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
bool iceLeft = true;

void dfs(int row, int col) {
	visited[row][col] = true;
	for (int k = 0; k < 4; k++) {
		int nRow = row + dx[k];
		int nCol = col + dy[k];
		if (nRow < 0 || nRow >= n || nCol < 0 || nCol >= m || visited[nRow][nCol] || ice[nRow][nCol] == 0) continue;
		dfs(nRow, nCol);
	}
}

void melt(int row, int col) {
	int cnt = 0;
	vector<pair<int, int>> v;
	for (int k = 0; k < 4; k++) {
		int nRow = row + dx[k];
		int nCol = col + dy[k];
		if (nRow < 0 || nRow >= n || nCol < 0 || nCol >= m) continue;
		if (ice[nRow][nCol] == 0) cnt++;
	}
	temp[row][col] = max(0, ice[row][col] - cnt);	
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ice[i][j];
		}
	}
	while (true) {
		memset(visited, 0, sizeof(visited));
		int pieces = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && ice[i][j] > 0) {
					if (pieces == 1) {
						cout << ret << "\n";
						return 0;
					}
					dfs(i, j);
					pieces++;
				}
			}
		}
		iceLeft = false;
		ret++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ice[i][j] != 0) {
					melt(i, j);
					iceLeft = true;
				}
			}
		}		
		if (!iceLeft) {
			cout << 0 << "\n";
			return 0;
		}
		copy(&temp[0][0], &temp[300][301], &ice[0][0]);

	}
	return 0;
	
}