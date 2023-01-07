#include <bits/stdc++.h>

using namespace std;

int m, n;
int box[1001][1001]; // �丶�� ������ ����
int visited[1001][1001]; // �ҿ� �ϼ� ����
queue<pair<int, int>> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int days;

void BFS() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 1) { // ���� �;��־��� �丶�䰡 �ִ� ���
				visited[i][j] = 0;
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newRow = row + dy[i];
			int newCol = col + dx[i];

			if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && box[newRow][newCol] == 0) { // ���� �丶���� �����¿쿡 ���� ���� �丶�䰡 �ִ� ���
				box[newRow][newCol] = 1; // �丶�䰡 ���� ���·� ����
				q.push({ newRow, newCol });
				visited[newRow][newCol] = visited[row][col] + 1; // �ҿ� �ϼ� 1�� �߰�
			}
		}
		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) { // ���� �ڽ��� ���� ���� �丶�䰡 �ִ� ���
				days = -1;
				return;
			}
			if (visited[i][j] > days) {
				days = visited[i][j];
			}
		}
	}
}


int main(void) {
	memset(box, 2, sizeof(box));
	memset(visited, -1, sizeof(visited));

	cin >> m >> n;

	int tomato; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato;
			box[i][j] = tomato;
		} 
	}

	BFS();

	cout << days;
}