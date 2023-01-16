#include <bits/stdc++.h>
using namespace std;
int arr[51][51];
int visited[51][51];
int row, col, cnt, ret = -1;
char c;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

void solve(int x, int y) {
	queue<pair<int, int>> q;
	cnt = 0;
	visited[x][y] = true;
	q.push({ x, y });
	while (!q.empty()) {
		cnt++;
		int px = q.front().first;
		int py = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = px + dx[k];
			int ny = py + dy[k];
			if (nx < 0 || ny < 0 || nx >= row || ny >= col || visited[nx][ny] > 0) continue;
			if (arr[nx][ny] == 1) {
				q.push({ nx, ny });
				visited[nx][ny] = visited[px][py] + 1;
				ret = max(ret, visited[nx][ny]);
			}
		}
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> c;
			if (c == 'L') arr[i][j] = 1;
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 1) {
				memset(visited, 0, sizeof(visited));
				solve(i, j);
			}
		}
	}
	cout << ret - 1 << '\n';
	return 0;
}