#include <bits/stdc++.h>

using namespace std;

int dp[1001];

int main() {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		// n-1 도형에서 오른쪽에 2*1 도형이 하나 붙은 형태 또는
		// n-2 도형에서 오른쪽에 1*2 가로 도형이 2개 붙은 형태, 2*2 도형이 하나 붙은 형태
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}
	cout << dp[n];

	return 0;
}