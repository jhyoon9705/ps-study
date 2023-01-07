#include <bits/stdc++.h>

using namespace std;

int N, M;
char arr[101][101];
bool visited[101][101];
long long myTeam = 0;
long long enemy = 0;
queue<pair<int, int>> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void BFS(int row, int col, char color) {
	int counter = 1;
	q.push({ row, col });
	visited[row][col] = true;

	while (!q.empty()) {
		int prevRow = q.front().first;
		int prevCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newRow = prevRow + dx[i];
			int newCol = prevCol + dy[i];

			if (color == 'W') {
				if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && visited[newRow][newCol] == false && arr[newRow][newCol] == 'W') {
					q.push({ newRow, newCol });
					visited[newRow][newCol] = true;
					counter++;
				}
			}
			else if (color == 'B') {
				if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && visited[newRow][newCol] == false && arr[newRow][newCol] == 'B') {
					q.push({ newRow, newCol });
					visited[newRow][newCol] = true;
					counter++;
				}
			}
		}
	}
	if (color == 'W') {
		myTeam += (int)pow(counter, 2);
	}
	else if (color == 'B') {
		enemy += (int)pow(counter, 2);
	}
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < M; j++) {
			arr[i][j] = input[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == false && arr[i][j] == 'W') {
				BFS(i, j, 'W');
			}
			else if (visited[i][j] == false && arr[i][j] == 'B') {
				BFS(i, j, 'B');
			}
		}
	}
	cout << myTeam << " " << enemy;

	return 0;
}