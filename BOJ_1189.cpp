#include <bits/stdc++.h>
using namespace std;

int r, c, k;
char arr[6][6];
int visited[6][6];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int ret = 0;

void solve(int x, int y) {
	if (visited[0][c - 1] == k) {
		ret++;
		return;
	}	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny]) continue;
		if (arr[nx][ny] == 'T') continue;
		visited[nx][ny] = visited[x][y] + 1;
		solve(nx, ny);
		visited[nx][ny] = 0;
	}
}

int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	visited[r - 1][0] = 1;
	solve(r - 1, 0);
	cout << ret << '\n';
	return 0;
}