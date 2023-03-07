#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int t, k, input;
int files[501];
int dp[501][501];
int sum[501];

int solve(int start, int end) {
	if (start == end) return files[start];
	int& ret = dp[start][end];
	if (~ret) return ret;
	ret = INF;
	for (int idx = start; idx < end; idx++) {
		ret = min(ret, solve(start, idx) + solve(idx + 1, end));
	}
	ret += sum[end] - sum[start - 1];
	return ret;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> k;
		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= k; i++) {
			cin >> files[i];
			sum[i] = files[i] + sum[i - 1];
		}
		cout << solve(1, k) - sum[k] << "\n";
	}
}