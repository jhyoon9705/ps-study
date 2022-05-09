#include <bits/stdc++.h>

using namespace std;

char grid[100][100];
bool visited[100][100] = { false };
int N;
queue<pair<int, int>> q;
int dX[4] = { -1, 1, 0, 0 };
int dY[4] = { 0, 0, -1, 1 };
int counter = 0;

void BFS(int row, int column, char c, bool redGreen) { // ���ϻ����� ��� redGreen = true
	q.push({ row, column });
	visited[row][column] = true;

	while (!q.empty()) {
		int prevRow = q.front().first;
		int prevCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newRow = prevRow + dX[i];
			int newCol = prevCol + dY[i];
			if (redGreen == false) { // ���ϻ����� �ƴ� ���
				if (newRow >= 0 && newCol >= 0 && newRow < N && newCol < N && grid[newRow][newCol] == c && visited[newRow][newCol] == false) {
					q.push({ newRow, newCol });
					visited[newRow][newCol] = true;
				}
			}
			else { // ���ϻ����� ���
				// R(Red)�� G(Green)�� ���� ������ �ν�, Ž���� ���� ���ڷδ� R�� G �� R�� ����
				if (c == 'R' && newRow >= 0 && newCol >= 0 && newRow < N && newCol < N && (grid[newRow][newCol] == 'R' || grid[newRow][newCol] == 'G') && visited[newRow][newCol] == false) {
					q.push({ newRow, newCol });
					visited[newRow][newCol] = true;
				}
				else if (c == 'B' && newRow >= 0 && newCol >= 0 && newRow < N && newCol < N && grid[newRow][newCol] == c && visited[newRow][newCol] == false) {
					q.push({ newRow, newCol });
					visited[newRow][newCol] = true;
				}
			}
			
		}
	}
}

int main() {
	cin >> N;
	int arr[2];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == 'R' && visited[i][j] == false) {
				BFS(i, j, 'R', false);
				counter++;
			}
			else if (grid[i][j] == 'G' && visited[i][j] == false) {
				BFS(i, j, 'G', false);
				counter++;

			}
			else if (grid[i][j] == 'B' && visited[i][j] == false) {
				BFS(i, j, 'B', false);
				counter++;
			}
		}
	}

	arr[0] = counter;

	memset(visited, 0, sizeof(visited)); // ���ϻ����� ��� Ž���� ���� visited �迭 �ʱ�ȭ
	counter = 0; // ���� counter�� 0���� �ʱ�ȭ

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((grid[i][j] == 'R' || grid[i][j] == 'G') && visited[i][j] == false) {
				BFS(i, j, 'R', true);
				counter++;
			}
			
			else if (grid[i][j] == 'B' && visited[i][j] == false) {
				BFS(i, j, 'B', true);
				counter++;
			}
		}
	}

	arr[1] = counter;

	cout << arr[0] << " " << arr[1] << endl;

}