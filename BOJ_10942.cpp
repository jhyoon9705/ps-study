#include <bits/stdc++.h>
using namespace std;

int n, m, s, e;
int arr[2002], dp[2002][2002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
	}
	for (int sz = 2; sz <= n; sz++) {
		for (int i = 1; i <= n - sz; i++) {
			if (arr[i] == arr[i + sz] && dp[i + 1][i + sz - 1]) dp[i][i + sz] = 1;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}
	return 0;	
}