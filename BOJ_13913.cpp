#include <bits/stdc++.h>
using namespace std;
const int MAX = 200004;
int n, k, ret, vis[MAX], pre[MAX], now;
vector<int> v;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	vis[n] = 1;
	q.push(n);
	while (q.size()) {
		now = q.front();
		q.pop();
		if (now == k) {
			ret = vis[now];
			break;
		}
		for (int next : {now + 1, now - 1, now * 2}) {
			if (next < MAX && next >= 0 && !vis[next]) {
				pre[next] = now;
				vis[next] = vis[now] + 1;
				q.push(next);
			}
		}
	}

	for (int i = k; i != n; i = pre[i]) {
		v.push_back(i);
	}
	v.push_back(n);

	cout << ret - 1 << "\n";

	reverse(v.begin(), v.end());
	for (int i : v) cout << i << ' ';
	return 0;
}