#include <bits/stdc++.h>
using namespace std;

int n;
long long ret;
long long arr[102], dp[102][22];

long long solve(int idx, long long res) {
	if (res < 0 || res > 20) return 0;
	long long& ret = dp[idx][res];
	if (ret) return ret;
	if (idx == n - 1) {
		if (res == arr[n]) return 1;
		return 0;
	}
	ret += solve(idx + 1, res + arr[idx + 1]);
	ret += solve(idx + 1, res - arr[idx + 1]);
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cout << solve(1, arr[1]) << "\n";
	return 0;
}