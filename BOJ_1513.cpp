#include <bits/stdc++.h>
using namespace std;

int n, m, c, x, y;
int arr[51][51], dp[51][51][51][51];
const int mod = 1000007;

int solve(int y, int x, int cnt, int prev) {
	if (y > n || x > m) return 0;
	if (y == n && x == m) {
		if (cnt == 0 && arr[y][x] == 0) return 1;
		if (cnt == 1 && arr[y][x] > prev) return 1;
		return 0;
	}
	int& ret = dp[y][x][cnt][prev];
	if (~ret) return ret;
	ret = 0;
	if (arr[y][x] == 0) {
		ret = (solve(y + 1, x, cnt, prev) + solve(y, x + 1, cnt, prev)) % mod;
	}
	else if (arr[y][x] > prev) {
		ret = (solve(y + 1, x, cnt - 1, arr[y][x]) + solve(y, x + 1, cnt - 1, arr[y][x])) % mod;
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;
	for (int i = 1; i <= c; i++) {
		cin >> y >> x;
		arr[y][x] = i;
	}
	for (int i = 0; i <= c; i++) {
		cout << solve(1, 1, i, 0) << " ";
	}
	return 0;
}