#include <bits/stdc++.h>
using namespace std;

int r, c;
char arr[1001][1001];
bool visited[1001][1001];
int num[1001][1001];
queue<pair<int, int>> q, q2;
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };
int jx, jy;

void BFS(int x, int y) {
	visited[x][y] = true;
	q.push({ x, y });
	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = px + dx[k];
			int ny = py + dy[k];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (arr[nx][ny] == '#' || visited[nx][ny] == true) continue;
			q.push({ nx, ny });
			visited[nx][ny] = true;
			num[nx][ny] = min(num[px][py] + 1, num[nx][ny]);
		}
	}
}

void isAlive() {
	num[jx][jy] = 0;
	q2.push({ jx, jy });
	while (!q2.empty()) {
		int px = q2.front().first;
		int py = q2.front().second;
		q2.pop();
		for (int k = 0; k < 4; k++) {
			int nx = px + dx[k];
			int ny = py + dy[k];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				cout << num[px][py] + 1 << '\n';
				return;
			}
			if (num[nx][ny] == 1002 || num[px][py] + 1 >= num[nx][ny]) continue;
			num[nx][ny] = num[px][py] + 1;
			q2.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE" << '\n';
}

int main() {
	cin >> r >> c;
	fill(&num[0][0], &num[1000][1001], 1001);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'F') num[i][j] = 0;
			else if (arr[i][j] == 'J') {
				jx = i;
				jy = j;
			}
			else if (arr[i][j] == '#') num[i][j] = 1002;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'F') {
				memset(visited, false, sizeof(visited));
				BFS(i, j);
			}
		}
	}

	isAlive();
	return 0;
}