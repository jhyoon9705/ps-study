// n�� m������ �̵����� ���� �ִ�� ȹ���� �� �ִ� ������ ����
// n�� m���� �ִ� ������ �� + max(���� ĭ or ���� ĭ or ���� �� �밢�� ĭ���� �� �� ȹ���� �� �ִ� ������ ��)

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