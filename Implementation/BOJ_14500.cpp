#include <bits/stdc++.h>

using namespace std;

int arr[501][501];
bool visited[501][501];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int maxResult = 0;
int N, M;

// depth 4 DFS 진행
void tetromino(int row, int col, int cnt, int currentScore) {
	if (cnt == 4) {
		maxResult = max(maxResult, currentScore);
		return;
	}

	// ㄱ, ㄴ, ㅡ, ㄹ, ㅁ
	for (int i = 0; i < 4; i++) {
		int newRow = row + dx[i];
		int newCol = col + dy[i];

		if (newRow < 1 || newCol < 1 || newRow > N || newCol > M || visited[newRow][newCol] == true) continue;

		visited[newRow][newCol] = true;
		tetromino(newRow, newCol, cnt + 1, currentScore + arr[newRow][newCol]);
		visited[newRow][newCol] = false; // back-tracking
	}

	// DFS로 만들어지지 않는 블럭들
	if (row - 1 >= 1 && col - 1 >= 1 && row + 1 <= N) { // ㅓ
		maxResult = max(maxResult, arr[row - 1][col] + arr[row][col - 1] + arr[row][col] + arr[row + 1][col]);
	}
	if (row - 1 >= 1 && col + 1 <= M && row + 1 <= N) { // ㅏ
		maxResult = max(maxResult, arr[row - 1][col] + arr[row][col + 1] + arr[row][col] + arr[row + 1][col]);
	}
	if (col - 1 >= 1 && col + 1 <= M && row + 1 <= N) { // ㅗ
		maxResult = max(maxResult, arr[row][col] + arr[row + 1][col] + arr[row + 1][col - 1] + arr[row + 1][col + 1]);
	}
	if (col - 1 >= 1 && col + 1 <= M && row + 1 <= N) { // ㅜ
		maxResult = max(maxResult, arr[row][col - 1] + arr[row][col] + arr[row][col + 1] + arr[row + 1][col]);
	}

}

int main() {	
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			visited[i][j] = true;
			tetromino(i, j, 1, arr[i][j]);
			visited[i][j] = false; // back-tracking
		}
	}
	cout << maxResult;
	return 0;
}