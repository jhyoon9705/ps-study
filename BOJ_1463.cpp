#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int dp[MAX+1];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = i - 1;
	}

	for (int i = 1; i <= n; i++) {
		if (i * 3 <= MAX) {
			dp[i * 3] = min(dp[i * 3], dp[i] + 1);
		}
		if (i * 2 <= MAX) {
			dp[i * 2] = min(dp[i * 2], dp[i] + 1);
		}
		if (i + 1 <= MAX) {
			dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		}
	}

	cout << dp[n];

	return 0;
}