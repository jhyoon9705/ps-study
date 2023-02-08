#include <bits/stdc++.h>
using namespace std;

int n;
int arr[16][16], dp[16][1 << 16];
const int INF = 987654321;

int solve(int here, int visited) {
	if (visited == (1 << n) - 1) {
		return arr[here][0] ? arr[here][0] : INF;
	}
	int& ret = dp[here][visited];
	if (~ret) return ret;
	ret = INF;
	for (int i = 0; i < n; i++) {
		if (visited & (1 << i)) continue;
		if (arr[here][i] == 0) continue;
		ret = min(ret, solve(i, visited | (1 << i)) + arr[here][i]);
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 1) << "\n";
	return 0;
}