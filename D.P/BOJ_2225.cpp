#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000

int n, k;
int dp[201][201];

int main() {
	fill(&dp[0][0], &dp[200][201], 1);
	cin >> n >> k;

	for (int i = 0; i <= 200; i++) {
		dp[2][i] = i + 1;
	}
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	cout << dp[k][n];

	return 0;
}