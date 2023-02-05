#include <bits/stdc++.h>
using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };
int arr[52][52], visited[52][52];
int n, m;
queue<pair<int, int>> q;
map<int, int> mp;
int roomNum, bigRoom, big;

int dfs(int y, int x, int rn) {
	int areaCnt = 1;
	visited[y][x] = rn;
	q.push({ y, x });
	while (!q.empty()) {
		int py = q.front().first;
		int px = q.front().second;
		int num = arr[py][px];
		q.pop();
		for (int k = 0; k < 4; k++) {
			if (num & (1 << k)) continue;
			int nx = px + dx[k];
			int ny = py + dy[k];
			if (visited[ny][nx] != 0) continue;
			q.push({ ny, nx });
			visited[ny][nx] = rn;
			areaCnt++;
		}
	}
	mp[roomNum] = areaCnt;
	return areaCnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				roomNum++;
				bigRoom = max(bigRoom, dfs(i, j, roomNum));
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i + 1 < m) {
				int a = visited[i + 1][j];
				int b = visited[i][j];
				if (a != b) {
					big = max(big, mp[a] + mp[b]);
				}
			}
			if (j + 1 < n) {
				int a = visited[i][j + 1];
				int b = visited[i][j];
				if (a != b) {
					big = max(big, mp[a] + mp[b]);
				}
			}
		}
	}
	cout << roomNum << "\n";
	cout << bigRoom << "\n";
	cout << big << "\n";
	return 0;
}