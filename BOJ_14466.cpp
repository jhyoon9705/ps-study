#include <bits/stdc++.h>
using namespace std;

int n, k, r, a, b, c, d, ret;
int arr[101][101], visited[101][101];
vector<pair<int, int>> road[101][101];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

bool isBridge(int row, int col, int nRow, int nCol) {
	vector<pair<int, int>> roads = road[row][col];
	for (auto _r : roads) {
		if (_r.first == nRow && _r.second == nCol) return true;
	}
	return false;
}

void solve(int row, int col) {
	visited[row][col] = 1;
	for (int i = 0; i < 4; i++) {
		int nRow = row + dy[i];
		int nCol = col + dx[i];
		if (nRow >= 1 && nRow <= n && nCol >= 1 && nCol <= n && !visited[nRow][nCol] && !isBridge(row, col, nRow, nCol)) {
			if (arr[nRow][nCol] == 1) ret++;
			solve(nRow, nCol);
		}
	}
}

int main() {
	cin >> n >> k >> r;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> c >> d;
		road[a][b].push_back({ c, d });
		road[c][d].push_back({ a, b });
	}
	for (int i = 0; i < k; i++) {
		int row, col;
		cin >> row >> col;
		arr[row][col] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1) {
				solve(i, j);
				memset(visited, 0, sizeof(visited));
			}
		}
	}
	ret = k * (k - 1) / 2 - (ret / 2);
	cout << ret << "\n";
	return 0;
}