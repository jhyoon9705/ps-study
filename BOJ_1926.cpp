#include <bits/stdc++.h>

using namespace std;

int row, col;
int arr[501][501];
bool visited[501][501];
queue<pair<int, int>> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int maxArea = 0;

void BFS(int r, int c) {
	int area = 1;
	q.push({ r, c });
	visited[r][c] = true;

	while (!q.empty()) {
		int prevRow = q.front().first;
		int prevCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newRow = prevRow + dx[i];
			int newCol = prevCol + dy[i];
			if (newRow >= 1 && newRow <= row && newCol >= 1 && newCol <= col && visited[newRow][newCol] == false && arr[newRow][newCol] == 1) {
				q.push({ newRow, newCol });
				visited[newRow][newCol] = true;
				area++;
			}
		}
	}
	maxArea = max(maxArea, area);
}

int main() {
	cin >> row >> col;
	
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			int input;
			cin >> input;
			arr[i][j] = input;
		}
	}

	int pictureNum = 0;

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				pictureNum++;
				BFS(i, j);
			}
		}
	}

	cout << pictureNum << '\n';
	cout << maxArea << '\n';

	return 0;
}