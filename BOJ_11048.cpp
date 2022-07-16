// n행 m열까지 이동했을 때의 최대로 획득할 수 있는 사탕의 수는
// n행 m열에 있는 사탕의 수 + max(왼쪽 칸 or 위쪽 칸 or 왼쪽 위 대각선 칸까지 올 때 획득할 수 있는 사탕의 수)

#include <bits/stdc++.h>

using namespace std;

int maze[1001][1001], dp[1001][1001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maze[i][j];
		}
	}

	dp[1][1] = maze[1][1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = maze[i][j] + max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
		}
	}

	cout << dp[n][m];
}