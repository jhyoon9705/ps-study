#include <bits/stdc++.h>
using namespace std;

int arr[11][11];
int visited[11][11];
int n;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int ret = 987654321;

int setFlower(int x, int y) {
	visited[x][y] = 1;
	int price = arr[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		visited[nx][ny] = 1;
		price += arr[nx][ny];
	}
	return price;
}

void removeFlower(int x, int y) {
	visited[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		visited[nx][ny] = 0;
	}
}

bool check(int x, int y) {
	if (visited[x][y]) return 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) return 0;
	}
	return 1;
}

void solve(int cnt, int sum) {
	if (cnt == 3) {
		ret = min(ret, sum);
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check(i, j)) {
				solve(cnt + 1, sum + setFlower(i, j));
				removeFlower(i, j);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 0);
	cout << ret << '\n';
	return 0;
}