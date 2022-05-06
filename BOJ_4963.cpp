#include <bits/stdc++.h>

using namespace std;

int w, h;
int arr[50][50] = { 0 };
bool visited[50][50] = { 0 };
queue <pair<int, int>> q;
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void BFS(int row, int col) {
	int prevRow, prevCol, newRow, newCol;
	
	visited[row][col] = true;
	q.push({ row, col });
	
	while (!q.empty()) {
		prevRow = q.front().first;
		prevCol = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			newRow = prevRow + dx[i];
			newCol = prevCol + dy[i];
			if (newRow >= 0 && newCol >= 0 && newRow < h && newCol < w && arr[newRow][newCol] == 1 && visited[newRow][newCol] == false) {
				q.push({ newRow, newCol });
				visited[newRow][newCol] = true;
			}
		}
	}
}

int main() {
	int island;

	while (1) {
		cin >> w >> h;

		memset(visited, 0, sizeof(visited)); // 한 턴 끝나고 배열 초기화
		memset(arr, 0, sizeof(arr));
		island = 0;

		if (w == 0 && h == 0) {
			break;
		}

		int input; 

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> input;
				arr[i][j] = input;
			}
		}

		for (int m = 0; m < h; m++) {
			for (int n = 0; n < w; n++) {
				if (arr[m][n] == 1 && visited[m][n] == false) {
					BFS(m, n); // 방문하지 않은 곳 중 땅인 곳이 있으면 BFS 호출
					island++;
				}
			}
		}

		cout << island << endl;
	}
}