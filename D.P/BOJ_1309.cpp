#include <bits/stdc++.h>

using namespace std;

#define MOD 9901;

// dp[i][0]: ox / dp[i][1]: xo / dp[i][2] : xx
int dp[100000][3];


int main() {
	int n;
	cin >> n;

	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;

	return 0;
}