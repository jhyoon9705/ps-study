#include <bits/stdc++.h>

using namespace std;

int main() {
	int arr[10001], dp[10001];
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		// i번째 잔을 마시고 + max(i-2번째 잔까지의 최대 or i-1번째 잔도 마시고 i-2번째 잔은 마시지 않고 i-3번째 잔까지의 최대
		dp[i] = arr[i] + max(dp[i - 2], arr[i - 1] + dp[i - 3]);

		// 두 잔을 연속으로 마시지 않았을 경우도 고려
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[n];
}