#include <bits/stdc++.h>
using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, -1, 0, 1 };
int visited[101][101];
int n, x, y, d, g, ret;
vector<int> v;

void dCurve(int sx, int sy, int dir) {
	v.clear();
	visited[sy][sx] = 1;
	v.push_back(dir);
	if (g >= 1) {
		v.push_back((dir + 1) % 4);
	}
	for (int i = 2; i <= g; i++) {
		int vSize = v.size();
		for (int j = 0; j < vSize / 2; j++) {
			v.push_back((v[j] + 2) % 4);
		}
		for (int j = vSize / 2; j < vSize; j++) {
			v.push_back(v[j]);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int nx = sx + dx[v[i]];
		int ny = sy + dy[v[i]];
		visited[ny][nx] = 1;
		sx = nx;
		sy = ny;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		dCurve(x, y, d);
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]) ret++;
		}
	}
	cout << ret << '\n';
	return 0;
}