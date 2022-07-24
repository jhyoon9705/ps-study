#include <bits/stdc++.h>

using namespace std;

int dp[1025][1025];
int arr[1025][1025];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x1, y1, x2, y2, input;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input;

			if (i == 1 && j == 1) dp[i][j] = input;
			else if (i == 1) dp[i][j] = input + dp[i][j - 1];
			else if (j == 1) dp[i][j] = input + dp[i - 1][j];
			else dp[i][j] = input + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]; // (1,1)부터 (i,j)까지의 누적 합 구하기

		}
	}

	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		int answer = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << answer << '\n';
	}

	return 0;
}