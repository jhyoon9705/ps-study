#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[250][250];
int visited[250][250];
queue<pair<int, int>> q;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int counter = 0;

void BFS(int row, int col) {
	q.push({ row, col });
	visited[row][col] = true;
	
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		arr[r][c] = 0;

		for (int i = 0; i < 8; i++) {
			int newR = r + dy[i];
			int newC = c + dx[i];

			if (newR >= 0 && newC >= 0 && newR < m && newC < n && visited[newR][newC] == false && arr[newR][newC] == 1) {
				arr[newR][newC] = 0;
				visited[newR][newC] = true;
				q.push({ newR, newC });
			}
		}
	}
	counter++;

}

int main(void) {
	memset(arr, 0, sizeof(arr));
	memset(visited, false, sizeof(arr));

	cin >> m >> n;

	int input;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			arr[i][j] = input;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				BFS(i, j);
			}
		}
	}

	cout << counter;

}