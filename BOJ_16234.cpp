#include <bits/stdc++.h>

using namespace std;

int N, L, R;
int arr[51][101];
bool visited[51][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int sum = 0;
bool flag = true;
vector<pair<int, int>> v;
queue<pair<int, int>> q;

void BFS(pair<int, int> s) {
	q.push(s);
	visited[s.first][s.second] = true;

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newRow = row + dx[i];
			int newCol = col + dy[i];

			if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && visited[newRow][newCol] == false) {
				if (abs(arr[newRow][newCol] - arr[row][col]) >= L && abs(arr[newRow][newCol] - arr[row][col]) <= R) {
					q.push({ newRow, newCol });
					visited[newRow][newCol] = true;
					v.push_back({ newRow, newCol });
					sum += arr[newRow][newCol];
				}
			}
		}
	}
}

void clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

int main() {
	int days = 0;
	cin >> N >>  L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	while (flag) {
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					v.clear();
					v.push_back({ i, j });
					sum = arr[i][j];
					BFS({ i, j });
				}

				if (v.size() >= 2) {
					flag = true;
					for (int i = 0; i < v.size(); i++) {
						arr[v[i].first][v[i].second] = sum / v.size();
					}
				}
			}
		}
		if (flag) days++;
		clear();
	}
	cout << days;
}