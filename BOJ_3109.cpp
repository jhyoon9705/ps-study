#include <bits/stdc++.h>
using namespace std;

int r, c, ret;
char arr[10002][502];
bool visited[10002][502];
const int dx[3] = { 1, 1, 1 };
const int dy[3] = { -1, 0, 1 };
bool check;

void solve(int y, int x) {
	visited[y][x] = true;
	if (x == c - 1) {
		ret++;
		check = true;
		return;
	}
	for (int k = 0; k < 3; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
		if (arr[ny][nx] == '.') {
			solve(ny, nx);
			if (check) return;
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < c; j++) {
			arr[i][j] = input[j];
		}
	}
	for (int i = 0; i < r; i++) {
		check = false;
		solve(i, 0);
	}
	cout << ret << "\n";
	return 0;
}