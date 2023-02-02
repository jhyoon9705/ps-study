#include <bits/stdc++.h>
using namespace std;

int n, k;
struct A {
	int wT, wM, bT, bM;
};
vector<A> v;
int dp[101][100001];

int solve(int idx, int tSum) {
	if (idx == n) return 0;
	int& ret = dp[idx][tSum];
	if (ret) return ret;
	ret = -1e6;
	if (tSum - v[idx].bT >= 0) ret = max(ret, solve(idx + 1, tSum - v[idx].bT) + v[idx].bM);
	if (tSum - v[idx].wT >= 0) ret = max(ret, solve(idx + 1, tSum - v[idx].wT) + v[idx].wM);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a1, a2, b1, b2;
		cin >> a1 >> a2 >> b1 >> b2;
		v.push_back({ a1, a2, b1, b2 });
	}
	cout << solve(0, k) << "\n";
	return 0;
}