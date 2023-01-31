#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[32][32];

long long solve(int w, int h) {
	if (w == 0 && h == 0) return 1;
	if (dp[w][h]) return dp[w][h];
	long long& ret = dp[w][h];
	if (w > 0) ret += solve(w - 1, h + 1);
	if (h > 0) ret += solve(w, h - 1);
	return ret;
}

int main() {
	while (true) {
		cin >> n;
		if (n == 0) break;
		cout << solve(n, 0) << "\n";
	}
	return 0;
}