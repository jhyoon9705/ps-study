#include <bits/stdc++.h>

using namespace std;

int dp[100001];
vector<int> v;

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	fill(dp, dp + 100001, 100001);
	dp[0] = 0;

	for (int i = 0; i < (int)v.size(); i++) {
		int value = v.at(i);
		for (int j = value; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - value] + 1);
		}
	}

	if (dp[k] == 100001) {
		cout << -1;
		return 0;
	}

	
	cout << dp[k];

	return 0;
}