#include <bits/stdc++.h>
using namespace std;

int n, m, c, input, dp[24][1 << 14][24];
vector<int> v;

int solve(int here, int got, int capacity) {
	if (here == m) return 0;
	int& ret = dp[here][got][capacity];
	if (ret) return ret;
	ret = max(ret, solve(here + 1, got, c));
	for (int i = 0; i < n; i++) {
		bool alreadyGot = got & (1 << i);
		bool canGet = (capacity - v[i]) >= 0;
		if (!alreadyGot && canGet) ret = max(ret, solve(here, got | (1 << i), capacity - v[i]) + 1);
	}
	return ret;
}

int main() {
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}
	cout << solve(0, 0, c) << "\n";
	return 0;
}