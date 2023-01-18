#include <bits/stdc++.h>
using namespace std;

int n, k;
int sec[200004];
int num[200004];
queue<int> q;

void solve() {
	q.push(n);
	sec[n] = 1;
	num[n] = 1;

	while (!q.empty()) {
		int _t = q.front();
		q.pop();
		for (int next : {_t - 1, _t + 1, _t * 2}) {
			if (0 <= next && next <= 200000) {
				if (!sec[next]) {
					q.push(next);
					sec[next] = sec[_t] + 1;
					num[next] += num[_t];
				}
				else if (sec[next] == sec[_t] + 1) {
					num[next] += num[_t];
				}
			}
		}		
	}
}

int main() {
	cin >> n >> k;
	if (n == k) {
		cout << "0" << '\n';
		cout << "1" << '\n';
		return 0;
	}
	solve();

	cout << sec[k] - 1 << '\n';
	cout << num[k] << '\n';
	return 0;
}