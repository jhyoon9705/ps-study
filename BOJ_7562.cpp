#include <bits/stdc++.h>

using namespace std;

int N, I;
int startX, startY, endX, endY;
int board[300][300] = { 0 }; // 해당 좌표까지 올 때 최소 이동 수
bool visited[300][300] = { false };
queue<pair<int, int>> q;
int dX[8] = { -2, -1, 1, 2, 2, 1, -1, -2 }; // 나이트의 X축 이동 좌표
int dY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; // 나이트의 Y축 이동 좌표
vector<int> v;
int num = 0;

void BFS(int X, int Y) {
	visited[X][Y] = true;
	q.push({ X, Y });
	
	while (!q.empty()) {
		int prevRow = q.front().first;
		int prevCol = q.front().second;
		q.pop();

		if (prevRow == endX && prevCol == endY) { // 목표로 하는 도착점에 도착한 경우
			cout << board[prevRow][prevCol] << endl;
			while (!q.empty()) {
				q.pop(); // queue 정리
			}
			break;
		}

		for (int i = 0; i < 8; i++) {
			int newRow = prevRow + dX[i];
			int newCol = prevCol + dY[i];

			if (newRow >= 0 && newCol >= 0 && newRow < I && newCol < I && visited[newRow][newCol] == false) {
				visited[newRow][newCol] = true;
				q.push({ newRow, newCol });
				board[newRow][newCol] = board[prevRow][prevCol] + 1; // 특정 칸까지 오기위해 이동 횟수 = 이전 칸까지 오기위해 이동 횟수 + 1
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> I;
		cin >> startX >> startY;
		cin >> endX >> endY;

		BFS(startX, startY);
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
	}
}