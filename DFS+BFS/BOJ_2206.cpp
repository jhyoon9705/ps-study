#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int r, c;
int visited[1000][1000][2];
int bfs(int row, int col, vector<string>& graph) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},1 });
	visited[0][0][1] = 1;

	while (!q.empty()) {
		int prevX = q.front().first.first;
		int prevY = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if (prevX == r - 1 && prevY == c - 1) { //도착지에 도달하면 return
			return visited[prevX][prevY][block];
		}

		for (int i = 0; i < 4; i++) {
			int nextX = prevX + dir[i][0];
			int nextY = prevY + dir[i][1];
			if (nextX >= 0 && nextX < r && nextY >= 0 && nextY < c) {
				//다음 칸이 벽이고 뚫을 수 있을 때
				if (graph[nextX][nextY] == '1' && block) {
					q.push({ {nextX, nextY}, 0 });
					visited[nextX][nextY][block - 1] = visited[prevX][prevY][block] + 1;
				}
				//다음 칸이 0이고 방문하지 않았을 때
				else if (graph[nextX][nextY] == '0' && visited[nextX][nextY][block] == 0) {
					q.push({ {nextX, nextY}, block });
					visited[nextX][nextY][block] = visited[prevX][prevY][block] + 1;
				}
			}
		}

	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;
	vector<string> graph(r);
	for (int i = 0; i < r; i++) {
		cin >> graph[i];
	}
	cout << bfs(0, 0, graph);
	return 0;
}
// --------------------------------------------------
// 시간 초과
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> wall;
int arr[1001][1001];
int arrCpy[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int answer = 1000001;

void copyInit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arrCpy[i][j] = arr[i][j];
			visited[i][j] = 0;
		}
	}
}

void BFS() {
	q.push({ 0, 0 });
	visited[0][0] = 1;

	while (!q.empty()) {
		int prevX = q.front().first;
		int prevY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = prevX + dx[i];
			int newY = prevY + dy[i];
			
			if (newX >= 0 && newX < n && newY >= 0 && newY < m && visited[newX][newY] == 0 && arrCpy[newX][newY] == 0) {
				q.push({ newX, newY });
				visited[newX][newY] = visited[prevX][prevY] + 1;
			}
		}
	}
	if (visited[n-1][m-1] != 0) answer = min(answer, visited[n - 1][m - 1]);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 1) {
				wall.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < (int)wall.size(); i++) {
		copyInit();
		arrCpy[wall[i].first][wall[i].second] = 0;
		BFS();
	}

	if (answer == 1000001) cout << -1;
	else cout << answer;
	
	return 0;
}