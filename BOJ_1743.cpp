#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int arr[101][101] = { 0 };
bool visited[101][101] = { false };
queue <pair<int, int>> q;
int result = 1;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> v;

void BFS(int x, int y) {
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		int prevX = q.front().first;
		int prevY = q.front().second;
		q.pop();

			for (int i = 0; i < 4; i++) {
			int nX = prevX + dx[i];
			int nY = prevY + dy[i];

			if (nX >= 1 && nY >= 1 && nX <= n && nY <= m && visited[nX][nY] != true && arr[nX][nY] == 1) {
				q.push({ nX, nY });
				visited[nX][nY] = true;
				result++;
			}
		}

	}
}


int main() {
	cin >> n >> m >> k;

	int x, y;

	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				BFS(i, j);
				v.push_back(result);
				result = 1;
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.back();
}