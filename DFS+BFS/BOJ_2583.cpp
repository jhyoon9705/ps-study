#include <bits/stdc++.h>

using namespace std;

int m, n, k;
int arr[100][100] = { 0 };
int visited[100][100] = { false };
queue<pair<int, int>> q;
int dX[4] = { -1, 0, 1, 0 };
int dY[4] = { 0, 1, 0, -1 };
vector<int> result;
int counter = 0;


void BFS(int x, int y) {
	q.push({ x, y });
	visited[x][y] = true;
	counter++;

	while (!q.empty()) {
		int prevX = q.front().first;
		int prevY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = prevX + dX[i];
			int newY = prevY + dY[i];

			if (newX >= 0 && newY >= 0 && newX < m && newY < n && arr[newX][newY] != 1 && visited[newX][newY] == false) {
				q.push({ newX, newY });
				visited[newX][newY] = true;
				counter++;
			}
		}
	}
	result.push_back(counter);
	counter = 0;
}

int main() {
	cin >> m >> n >> k;

	int sX, sY, eX, eY;
	for (int i = 0; i < k; i++) {
		cin >> sX >> sY >> eX >> eY;
		for (int j = sX; j < eX; j++) {
			for (int k = sY; k < eY; k++) {
				arr[k][j] = 1; // 주의) 문제에서 주어진 좌표가 일반 배열의 x, y축과는 다름
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 1 && visited[i][j] == false) {
				BFS(i, j);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << int(result.size()) << endl;
	for (int i = 0; i < int(result.size()); i++) {
		cout << result[i] << ' ';
	}
}