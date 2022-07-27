#include <bits/stdc++.h>

using namespace std;

int r1, c1, r2, c2;
int n;
int board[200][200];
int dr[6] = { -2, -2, 0, 0, 2, 2 };
int dc[6] = { -1, +1, -2, +2, -1, +1 };
queue <pair<int, int>> q;

void BFS(int r, int c) {
	q.push({ r, c });
	board[r][c] = 0;

	while (!q.empty()) {
		int prevR = q.front().first;
		int prevC = q.front().second;
		q.pop();

		if (prevR == r2 && prevC == c2) break;

		for (int i = 0; i < 6; i++) {
			int newR = prevR + dr[i];
			int newC = prevC + dc[i];

			if (newR < 0 || newC < 0 || newR >= n || newC >= n) continue;
			if (board[newR][newC] == -1) {
				board[newR][newC] = board[prevR][prevC] + 1;
				q.push({ newR, newC });
			}
		}
	}
} 

int main() {
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;

	memset(board, -1, sizeof(board));
	BFS(r1, c1);

	cout << board[r2][c2];
}