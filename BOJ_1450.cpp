#include <bits/stdc++.h>
using namespace std;

int n, c;
long long arr[32], ret;
vector<int> v, v2;

void solve(int idx, int _n, vector<int>& v, int sum) {
	if (sum > c) return;
	if (idx > _n) {
		v.push_back(sum);
		return;
	}
	solve(idx + 1, _n, v, sum + arr[idx]);
	solve(idx + 1, _n, v, sum);
	return;
}

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	solve(0, n / 2 - 1, v, 0);
	solve(n / 2, n - 1, v2, 0);
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());
	for (int b : v) {
		if (c - b >= 0) ret += ((int)(upper_bound(v2.begin(), v2.end(), c - b) - v2.begin()));
	}
	cout << ret << "\n";
	return 0;
}