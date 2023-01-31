#include <bits/stdc++.h>
using namespace std;

int n, ret;
int dp[1000002];

void solve(int num) {
	if (num == 0) return;
	cout << num << " ";
	if (num % 3 == 0 && dp[num] == (dp[num / 3] + 1)) solve(num / 3);
	else if (num % 2 == 0 && dp[num] == (dp[num / 2] + 1)) solve(num / 2);
	else if (num - 1 >= 0 && dp[num] == (dp[num  - 1] + 1)) solve(num  - 1);
	return;
}

int main() {
	fill(&dp[0], &dp[0] + 1000002, 987654321);
	cin >> n;
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
		dp[i] = min(dp[i - 1] + 1, dp[i]);
	}
	cout << dp[n] << "\n";
	solve(n);
	return 0;
}