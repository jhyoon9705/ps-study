#include <bits/stdc++.h>
using namespace std;

int arr[100002], i = 0;
int dp[100002][5][5];

int check(int from, int to) {
	if (from == 0) return 2;
	if (from == to) return 1;
	if (abs(from - to) == 2) return 4;
	return 3;
}

int solve(int idx, int left, int right) {
	if (idx == i) return 0;
	int& ret = dp[idx][left][right];
	if (~ret) return ret;
	int l = solve(idx + 1, arr[idx], right) + check(left, arr[idx]);
	int r = solve(idx + 1, left, arr[idx]) + check(right, arr[idx]);
	return ret = min(l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		cin >> arr[i];
		if (arr[i] == 0) break;
		i++;
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0) << "\n";
	return 0;
}