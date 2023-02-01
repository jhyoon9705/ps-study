// dp[c] = k => c라는 돈으로 얻을 수 있는 최대 칼로리 수 = k
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, c, p, m1, m2;
int dp[10001];

int main() {
	while (true) {
		scanf("%d %d.%d", &n, &m1, &m2);
		if (n == 0) break;
		int cost = m1 * 100 + m2;
		fill(dp, dp + 10001, 0);
		for (int i = 0; i < n; i++) {
			scanf("%d %d.%d", &c, &m1, &m2);
			p = m1 * 100 + m2;
			for (int j = p; j <= cost; j++) {
				dp[j] = max(dp[j], dp[j - p] + c);
			}
		}
		printf("%d\n", dp[cost]);
	}
	return 0;
}