#include <bits/stdc++.h>
using namespace std;

int n, m, d[52][52];
char arr[52][52];
int visited[52][52];
queue<pair<int, int>> q;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
string s;

bool check(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= m);
}

int solve(int x, int y) {
	if (!check(x, y) || arr[x][y] == 'H') return 0;
	if (visited[x][y]) {
		cout << -1 << "\n";
		exit(0);
	}
	int& ret = d[x][y];
	if (ret) return ret;
	visited[x][y] = 1;
	int value = (int)arr[x][y] - '0';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * value;
		int ny = y + dy[i] * value;
		ret = max(ret, solve(nx, ny) + 1);
	}
	visited[x][y] = 0;
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = s[j - 1];
		}
	}
	cout << solve(1, 1) << "\n";
	return 0;
}