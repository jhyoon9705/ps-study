#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int n, t, p, dp[1600002];

int main() {
	cin >> n;
	v.push_back({ 0, 0 });
	for (int i = 1; i <= n; i++) {
		cin >> t >> p;
		v.push_back({ t, p });
	}
	for (int i = 1; i <= n; i++) {
		dp[i + v[i].first] = max(dp[i + v[i].first], dp[i] + v[i].second);
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}
	cout << dp[n + 1] << "\n";
	return 0;
}