#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m;
int arr[9][9];
int visited[9][9];
int ret = INF;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;

vector<pair<int, int>> solve(int here, int dir) {
	vector<pair<int, int>> _change;
	int x = v[here].first;
	int y = v[here].second;
	if (arr[x][y] == 1) {
		while (true) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != 6) {
				if (arr[nx][ny] == 0) {
					arr[nx][ny] = 8;
					_change.push_back({ nx, ny });
				}
				x = nx;
				y = ny;
			}
			else break;
		}
	}
	else if (arr[x][y] == 2) {
		for (int i = 0; i <= 2; i += 2) {
			int px = x;
			int py = y;
			while (true) {
				int nx = px + dx[(dir + i) % 4];
				int ny = py + dy[(dir + i) % 4];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != 6) {
					if (arr[nx][ny] == 0) {
						arr[nx][ny] = 8;
						_change.push_back({ nx, ny });
					}
					px = nx;
					py = ny;
				}
				else break;
			}
		}
	}
	else if (arr[x][y] == 3) {
		for (int i = 0; i < 2; i++) {
			int px = x;
			int py = y;
			while (true) {
				int nx = px + dx[(dir + i) % 4];
				int ny = py + dy[(dir + i) % 4];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != 6) {
					if (arr[nx][ny] == 0) {
						arr[nx][ny] = 8;
						_change.push_back({ nx, ny });
					}
					px = nx;
					py = ny;
				}
				else break;
			}
		}
	}
	else if (arr[x][y] == 4) {
		for (int i = 0; i < 3; i++) {
			int px = x;
			int py = y;
			while (true) {
				int nx = px + dx[(dir + i) % 4];
				int ny = py + dy[(dir + i) % 4];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != 6) {
					if (arr[nx][ny] == 0) {
						arr[nx][ny] = 8;
						_change.push_back({ nx, ny });
					}
					px = nx;
					py = ny;
				}
				else break;
			}
		}
	}
	else if (arr[x][y] == 5) {
		for (int i = 0; i < 4; i++) {
			int px = x;
			int py = y;
			while (true) {
				int nx = px + dx[(dir + i) % 4];
				int ny = py + dy[(dir + i) % 4];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != 6) {
					if (arr[nx][ny] == 0) {
						arr[nx][ny] = 8;
						_change.push_back({ nx, ny });
					}
					px = nx;
					py = ny;
				}
				else break;
			}
		}
	}
	return _change;
}

void dfs(int here) {
	if (here == v.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) cnt++;
			}
		}
		ret = min(cnt, ret);
		return;
	}
	for (int k = 0; k < 4; k++) {
		vector<pair<int, int>> _change = solve(here, k);
		dfs(here + 1);
		for (auto b : _change) arr[b.first][b.second] = 0; // back-tracking
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) v.push_back({ i, j });
		}
	}
	dfs(0);
	cout << ret << '\n';
	return 0;
}