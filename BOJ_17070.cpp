#include <bits/stdc++.h>
using namespace std;

int n;
int arr[18][18], visited[18][18];
struct A {
	int x, y, t;
};
queue<A> q;

void solve(int r, int c) {
	visited[r][c] = 1;
	q.push({ r, c, 1 });
	while (!q.empty()) {
		int px = q.front().x;
		int py = q.front().y;
		int pt = q.front().t;
		q.pop();
		if (pt == 1) {
			if (py + 1 <= n && arr[px][py + 1] != 1) {
				q.push({ px, py + 1, 1 });
				visited[px][py + 1]++;
			}
			if (px + 1 <= n && py + 1 <= n && arr[px + 1][py] != 1 && arr[px][py + 1] != 1 && arr[px + 1][py + 1] != 1) {
				q.push({ px + 1, py + 1, 3 });
				visited[px + 1][py + 1]++;
			}
		}
		else if (pt == 2) {
			if (px + 1 <= n && arr[px + 1][py] != 1) {
				q.push({ px + 1, py, 2 });
				visited[px + 1][py]++;
			}
			if (px + 1 <= n && py + 1 <= n && arr[px + 1][py] != 1 && arr[px][py + 1] != 1 && arr[px + 1][py + 1] != 1) {
				q.push({ px + 1, py + 1, 3 });
				visited[px + 1][py + 1]++;
			}
		}
		else if (pt == 3) {
			if (py + 1 <= n && arr[px][py + 1] != 1) {
				q.push({ px, py + 1, 1 });
				visited[px][py + 1]++;
			}
			if (px + 1 <= n && arr[px + 1][py] != 1) {
				q.push({ px + 1, py, 2 });
				visited[px + 1][py]++;
			}
			if (px + 1 <= n && py + 1 <= n && arr[px + 1][py] != 1 && arr[px][py + 1] != 1 && arr[px + 1][py + 1] != 1) {
				q.push({ px + 1, py + 1, 3 });
				visited[px + 1][py + 1]++;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(1, 2);
	cout << visited[n][n] << '\n';
	return 0;
}