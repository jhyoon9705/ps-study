#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
int visited[62][62][62];
int arr[6][3] = { {9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 3, 9}, {1, 9, 3}};
struct str {
	int x, y, z;
};
queue<str> q;

int solve(int x, int y, int z) {
	visited[x][y][z] = 0;
	q.push({ x, y, z });
	while (!q.empty()) {
		int px = q.front().x;
		int py = q.front().y;
		int pz = q.front().z;
		q.pop();
		if (visited[0][0][0]) break;
		for (int i = 0; i < 6; i++) {
			int nx = max(0, px - arr[i][0]);
			int ny = max(0, py - arr[i][1]);
			int nz = max(0, pz - arr[i][2]);
			if (visited[nx][ny][nz] != 0) continue;
			visited[nx][ny][nz] = visited[px][py][pz] + 1;
			q.push({ nx, ny, nz });
		}
	}
	return visited[0][0][0];
}

int main() {
	cin >> n;
	if (n == 3) {
		cin >> a >> b >> c;
		cout << solve(a, b, c) << '\n';
	}
	else if (n == 2) {
		cin >> a >> b;
		cout << solve(a, b, 0) << '\n';
	}
	else {
		cin >> a;
		cout << solve(a, 0, 0) << '\n';
	}
	return 0;
}