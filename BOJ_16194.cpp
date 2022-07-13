#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int card[1001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}

	for (int i = 1; i <= n; i++) { // 총 i장을 구매
		dp[i] = card[i]; // i장 구매 시, 한 팩에 i장 들어있는 것을 구매
		for (int j = 1; j <= i; j++) {
			// i장 들어있는 것을 구매 or i-j장 구매 최소 비용 + j장 들어있는 것을 구매
			dp[i] = min(dp[i], dp[i - j] + card[j]);
		}
	}

	cout << dp[n];

	return 0;
}