#include <bits/stdc++.h>

using namespace std;

char arr[251][251];
bool visited[251][251];
int R, C;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
int totalSheep = 0;
int totalWolf = 0;

void BFS(int row, int col) {
	int sheep = 0;
	int wolf = 0;

	if (arr[row][col] == 'v') wolf++;
	else sheep++;

	q.push({ row, col });
	visited[row][col] = true;

	while (!q.empty()) {
		int prevRow = q.front().first;
		int prevCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newRow = prevRow + dx[i];
			int newCol = prevCol + dy[i];
			if (newRow >= 0 && newCol >= 0 && newRow < R && newCol < C && visited[newRow][newCol] == false && arr[newRow][newCol] != '#') {
				q.push({ newRow, newCol });
				visited[newRow][newCol] = true;
				if (arr[newRow][newCol] == 'v') wolf++;
				else if (arr[newRow][newCol] == 'o') sheep++;
			}
		}
	}

	if (sheep > wolf) totalSheep += sheep;
	else totalWolf += wolf;
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < C; j++) {
			arr[i][j] = input[j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if ((arr[i][j] == 'v' || arr[i][j] == 'o') && visited[i][j] == false) {
				BFS(i, j);
			}
		}
	}

	cout << totalSheep << " " << totalWolf;
	return 0;
}