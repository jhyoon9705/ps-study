#include <bits/stdc++.h>
using namespace std;

int n, ret = 404;
int coin[22];
string s;

void solve(int here) {
	if (here == n) {
		int sum = 0;
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (coin[j] & i) cnt++;
			}
			sum += min(cnt, n - cnt);
		}
		ret = min(ret, sum);
		return;
	}
	solve(here + 1);
	coin[here] = ~coin[here];
	solve(here + 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int status = 0;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'H') status |= (1 << j);
		}
		coin[i] = status;
	}
	solve(0);
	cout << ret << "\n";
	return 0;
}