#include <bits/stdc++.h>

using namespace std;

long long dp[101];

int main() {
	int t;
	cin >> t;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		for (int j = 4; j <= n; j++) {
			dp[j] = dp[j - 3] + dp[j - 2];
		}

		cout << dp[n] << '\n';
	}

	return 0;
}