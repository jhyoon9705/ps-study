// ex) 카드를 4장 살 때의 최댓값은
// 1. 카드 3장 살 때의 최댓값 + 1번 카드팩 값
// 2. 카드 2장 살 때의 최댓값 + 2번 카드팩 값
// 3. 카드 1장 살 때의 최댓값 + 3번 카드팩 값
// 4. 카드 0장 살 때의 최댓값(0) + 4번 카드팩 값
// 중 최댓값

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

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}

	cout << dp[n];

	return 0;
}