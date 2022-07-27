#include <bits/stdc++.h>

using namespace std;

int t, m, n, k;
int arr[51][51] = { 0 };
bool visited[51][51] = { 0 };
int counter = 0;
int dX[4] = { 0, 0, -1, 1 };
int dY[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;

void BFS(int startRow, int startCol) {
	q.push({ startRow, startCol });
	visited[startRow][startCol] = true;

	while (!q.empty()) {
		int prevRow = q.front().first;
		int prevCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newRow = prevRow + dX[i];
			int newCol = prevCol + dY[i];

			if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n && visited[newRow][newCol] == false && arr[newRow][newCol] == 1) {
				visited[newRow][newCol] = true;
				q.push({ newRow, newCol });

			}
		}
	}

}

int main() {
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		counter = 0;
		memset(visited, 0, sizeof(visited)); // 한 턴 끝나고 배열 초기화
		memset(arr, 0, sizeof(arr));

		cin >> m >> n >> k;

		for (int j = 0; j < k; j++) {
			int row, col;
			cin >> row >> col;
			arr[row][col] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == false && arr[i][j] == 1) { // 아직 방문하지 않은 곳 중에서 배추가 심겨져 있는 곳
					BFS(i, j); // 위 조건에 해당하는 지점으로부터 BFS 탐색 시작
					counter++;
				}
			}
		}


		cout << counter << endl;

	}


}