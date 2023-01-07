#include <bits/stdc++.h>

using namespace std;

long long dp[91];

int main() {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		//i자리 수보다 두자리 적은 수에서 01을 붙이거나, 한자리 적은 수에서 0을 붙임
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[n];

	return 0;
}