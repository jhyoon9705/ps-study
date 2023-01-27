#include<bits/stdc++.h>
using namespace std;
#define y ff
int n, m, T, x, d, k, a[54][54], ret, visited[54][54], y;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

bool flag = 1;
void _rotate(int y, int dir, int k) {
	vector<int> v;
	for (int i = 0; i < m; i++)v.push_back(a[y][i]);
	if (dir == 1)  rotate(v.begin(), v.begin() + k, v.end());
	else  rotate(v.begin(), v.begin() + m - k, v.end());
	for (int i = 0; i < m; i++) a[y][i] = v[i];
	return;
}
void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = (x + dx[i] + m) % m;
		if (ny < 0 || ny >= n) continue;
		if (visited[ny][nx]) continue;
		if (a[y][x] == a[ny][nx]) {
			visited[y][x] = visited[ny][nx] = 1;
			flag = 0;
			dfs(ny, nx);
		}
	}
}
bool findAdj() {
	flag = 1;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) continue;
			if (visited[i][j]) continue;
			dfs(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) a[i][j] = 0;
		}
	}
	return flag;
}
void setAverage() {
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) continue;
			sum += a[i][j];
			cnt++;
		}
	}
	double av = (double)sum / (double)cnt;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) continue;
			if ((double)a[i][j] > av) a[i][j]--;
			else if ((double)a[i][j] < av)a[i][j]++;
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> T;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < T; i++) {
		cin >> x >> d >> k;
		for (int j = x - 1; j < n; j += x) {
			_rotate(j, d, k);
		}
		if (findAdj())setAverage();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ret += a[i][j];
		}
	}
	cout << ret << "\n";
	return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

int n, m, t;
float sum, notZero, ret;
float arr[52][52];
int visited[52][52];
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
vector<pair<int, int>> temp;

// dfs
void eraseNum(int x, int y, float num) {
	temp.push_back({ x, y });
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny == -1) ny = m - 1;
		if (ny == m) ny = 0;
		if (nx < 1 || nx > n ) continue;
		if (visited[nx][ny]) continue;
		if (arr[nx][ny] == num) {
			eraseNum(nx, ny, num);
		}
	}
}

void solve(int x, int d, int k) {
	int idx = 1;
	for (int j = x; j <= n; j+= x) {
		if (d == 0) {
			for (int y = 0; y < k; y++) {
				rotate(arr[j], arr[j] + m - 1, arr[j] + m);
			}			
		}
		else if (d == 1) {
			for (int y = 0; y < k; y++) {
				rotate(arr[j], arr[j] + 1, arr[j] + m);
			}					
		}
	}

	int cnt = 0;
	for (int j = 1; j <= n; j++) {
		for (int k = 0; k < m; k++) {
			if (arr[j][k] != 0) {
				memset(visited, 0, sizeof(visited));
				float thisNum = arr[j][k];
				eraseNum(j, k, arr[j][k]);
				if (temp.size() > 1) {
					cnt++;
					for (auto p : temp) {
						arr[p.first][p.second] = 0;
						sum -= thisNum;
						notZero--;
					}
				}
				temp.clear();
			}
		}
	}
	if (cnt == 0) {
		float avg = sum / notZero;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					if (arr[i][j] > avg) arr[i][j]--;
					else if (arr[i][j] < avg) arr[i][j]++;
				}
			}
		}
	}	
}

int main() {
	cin >> n >> m >> t;
	notZero = (float)m * (float)n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	}
	int b1, b2, b3;
	for (int i = 0; i < t; i++) {
		cin >> b1 >> b2 >> b3;
		solve(b1, b2, b3);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			ret += arr[i][j];
		}
	}

	cout << (int)ret << '\n';
	return 0;
}*/