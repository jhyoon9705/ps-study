#include <bits/stdc++.h>

using namespace std;

#define MOD 10007
int n, k;
int dp[1001][1001];

int main() {
	fill(dp[0], dp[1001], 1);
	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	cout << dp[n][k];

	return 0;
}