#include <bits/stdc++.h>
using namespace std;
int n, mp, mf, ms, mv;
int b, c, d, e, sum;
int ret = 987654321;
struct S {
	int  mp, mf, ms, mv, cost;
} s[16];
map<int, vector<vector<int>>> ret_v;

int main() {
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++) {
		cin >> s[i].mp >> s[i].mf >> s[i].ms >> s[i].mv >> s[i].cost;
	}
	
	for (int i = 1; i < (1 << n); i++) {
		b = c = d = e = sum = 0;
		vector<int> v;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				v.push_back(j + 1);
				b += s[j].mp;
				c += s[j].mf;
				d += s[j].ms;
				e += s[j].mv;
				sum += s[j].cost;
			}
		}
		if (b >= mp && c >= mf && d >= ms && e >= mv) {
			if (ret >= sum) {
				ret = sum;
				ret_v[ret].push_back(v);
			}
		}
	}

	if (ret == 987654321) cout << -1 << '\n';
	else {
		sort(ret_v[ret].begin(), ret_v[ret].end());
		cout << ret << '\n';
		for (int a : ret_v[ret][0]) {
			cout << a << " ";
		}
	}
	return 0;
}