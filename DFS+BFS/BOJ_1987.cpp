#include <bits/stdc++.h>

using namespace std;

int R, C;
char arr[21][21];
bool visited[21][21];
bool alphabet[26];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int answer = 1;

void DFS(int row, int col, int cnt, char current) {
	alphabet[current - 'A'] = true;
	visited[row][col] = true;
	
	for (int i = 0; i < 4; i++) {
		int newRow = row + dx[i];
		int newCol = col + dy[i];

		if (newRow < 0 || newRow >= R || newCol < 0 || newCol >= C || visited[newRow][newCol] == true || alphabet[arr[newRow][newCol] - 'A'] == true) continue;
		
		answer = max(answer, cnt + 1);
		DFS(newRow, newCol, cnt + 1, arr[newRow][newCol]);
		alphabet[arr[newRow][newCol] - 'A'] = false;
		visited[newRow][newCol] = false;
	}
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

	DFS(0, 0, 1, arr[0][0]);
	cout << answer;

	return 0;
}