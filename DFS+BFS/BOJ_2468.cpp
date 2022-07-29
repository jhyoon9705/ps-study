#include <bits/stdc++.h>

using namespace std;

int n, maxValue = 0;
int arr[101][101];
int safe[101][101]; // 특정 높이만큼 비가 내렸을 때 잠기는 부분은 0, 안 잠기는 부분은 1
int visited[101][101];
queue<pair<int, int>> q;
int answer = 0;
int areaNum = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void BFS(int row, int col) {
	q.push({ row, col });
	visited[row][col] = 1;

	while (!q.empty()) {
		int prevRow = q.front().first;
		int prevCol = q.front().second;
		q.pop();

		for (int t = 0; t < 4; t++) {
			int newRow = prevRow + dx[t];
			int newCol = prevCol + dy[t];

			if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && safe[newRow][newCol] == 1 && visited[newRow][newCol] == 0) {
				q.push({ newRow, newCol });
				visited[newRow][newCol] = 1;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			maxValue = max(maxValue, arr[i][j]);
		}
	}

	for (int i = 1; i <= maxValue; i++) {
		memset(safe, 0, sizeof(safe));
		memset(visited, 0, sizeof(visited));
		areaNum = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[j][k] >= i) {
					safe[j][k] = 1;
				}
			}
		}
		
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (safe[j][k] == 1 && visited[j][k] == 0) {
					BFS(j, k);
					areaNum++;
				}
			}
		}
		answer = max(answer, areaNum);
	}

	cout << answer;

	return 0;
}