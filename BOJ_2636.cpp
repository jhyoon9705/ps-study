#include <bits/stdc++.h>
using namespace std;

int row, col;
int arr[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int visited[101][101];
vector<pair<int, int>> v;
int cnt1, cnt2;

// DFS
void solve(int a, int b) {
	visited[a][b] = 1;
	if (arr[a][b] == 1) {
		v.push_back({ a, b });
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = a + dx[i];
		int ny = b + dy[i];
		if (nx < 0 || ny < 0 || nx >= row || ny >= col || visited[nx][ny]) continue;
		solve(nx, ny);
	}
	return;
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
		}
	}
	
	while (true) {
		cnt2 = 0;
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		v.clear();
		solve(0, 0);
		for (pair<int, int> p : v) {
			cnt2++;
			arr[p.first][p.second] = 0;
		}
		bool isAllMelted = true;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (arr[i][j] != 0) isAllMelted = false;
			}
		}
		cnt1++;
		if (isAllMelted) break;
	}
	cout << cnt1 << '\n' << cnt2 << '\n';
	return 0;
} 