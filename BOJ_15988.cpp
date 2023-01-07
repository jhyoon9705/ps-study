#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000009
long long dp[1000001];

int main() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		for (int i = 4; i <= n; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
		}
		cout << dp[n] << "\n";
	}

	return 0;
}