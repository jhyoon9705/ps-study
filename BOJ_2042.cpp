// ∆Ê¿® ∆Æ∏Æ
#include <bits/stdc++.h>
using namespace std;

int n, m, k, i1, i2, i3;
long long i4;

long long sum(vector<long long>& tree, int i) {
	long long ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

void update(vector<long long>& tree, int i, long long diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	vector<long long> a(n + 1);
	vector<long long> tree(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(tree, i, a[i]);
	}
	m += k;
	while (m--) {
		cin >> i1;
		if (i1 == 1) {
			cin >> i2 >> i4;
			long long diff = i4 - a[i2];
			a[i2] = i4;
			update(tree, i2, diff);
		}
		else {
			cin >> i2 >> i3;
			cout << sum(tree, i3) - sum(tree, i2 - 1) << '\n';
		}
	}
	return 0;
}