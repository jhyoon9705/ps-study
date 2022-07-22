#include <bits/stdc++.h>

using namespace std;

int m, n, h, days = 0;
int tomato[102][102][102];
queue<pair<pair<int, int>, int>> q;
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

void BFS() {
	while (!q.empty()) {
		days++;
		int size = (int)q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int z = q.front().second;
			q.pop();

			for (int j= 0; j< 6; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				int nz = z + dz[j];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < h && tomato[nx][ny][nz] == 0) {
					q.push({ {nx, ny}, nz });
					tomato[nx][ny][nz] = 1;
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[j][k][i] == 0) { // 익지 않은 토마토가 있는 경우 -1을 출력
					cout << -1;
					return;
				}
			}
		}
	}

	// 모든 토마토가 익은 경우에도 반복문이 한번 더 도므로 -1
	cout << days - 1;
}

int main() {
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[j][k][i];
				if (tomato[j][k][i] == 1) {
					q.push({ {j, k}, i });
				}
			}
		}
	}

	BFS();
	return 0;
}