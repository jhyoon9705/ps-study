#include <bits/stdc++.h>

using namespace std;

// ex) 4를 만드는 경우의 수
// = 1에서 3을 더한 경우 + 2에서 2를 더한 경우 + 3에서 1을 더한 경우

int dp[11];

int main() {
	int t, n;
	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (t--) {
		cin >> n;
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}
		cout << dp[n] << endl;
	}
	return 0;
}