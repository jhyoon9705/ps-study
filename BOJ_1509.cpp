#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
string s;
int dp[2502][2502], dp2[2502], sSize;

int solve(int here) {
	if (here == sSize) return 0;
	if (dp2[here] != INF) return dp2[here];
	int& ret = dp2[here];
	for (int i = 1; here + i <= sSize; i++) {
		if (dp[here][i]) ret = min(ret, solve(here + i) + 1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	sSize = s.length();
	for (int i = 0; i < sSize; i++) dp[i][1] = 1;
	for (int i = 0; i < sSize - 1; i++) {
		if (s[i] == s[i + 1]) dp[i][2] = 1;
	}
	for (int _size = 3; _size <= sSize; _size++) {
		for (int j = 0; j + _size <= sSize; j++) {
			if (s[j] == s[j + _size - 1] && dp[j + 1][_size - 2]) dp[j][_size] = 1;
		}
	}

	fill(dp2, dp2 + 2502, INF);
	cout << solve(0) << "\n";
	return 0;
}