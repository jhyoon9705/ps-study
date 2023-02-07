#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
string dp[104], MAX_STR = "111111111111111111111111111111111111111111111111119";

string get_min_str(string a, string b) {
	if (a.size() == b.size()) return (a < b ? a : b);
	if (a.size() < b.size()) return a;
	return b;
}

int main() {
	cin >> t;
	fill(dp, dp + 104, MAX_STR);
	dp[0] = "";
	for (int i = 2; i < 104; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i - a[j] < 0) continue;
			if (j == 0 && dp[i - a[j]] == "") continue;
			dp[i] = get_min_str(dp[i], dp[i - a[j]] + to_string(j));
		}
	}
	while (t--) {
		string mx;
		cin >> n;
		int i = n / 2 - 1;
		while (i--) {
			mx += '1';
		}
		if (n % 2 == 0) mx += '1';
		else mx = '7' + mx;
		cout << dp[n] << " " << mx << "\n";
	}	
	return 0;
}