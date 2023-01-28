#include <bits/stdc++.h>
using namespace std;

int t, n, m, input, ret;
vector<int> a, b;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		ret = 0;
		for (int j = 0; j < n; j++) {
			cin >> input;
			a.push_back(input);
		}
		for (int k = 0; k < m; k++) {
			cin >> input;
			b.push_back(input);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for (int j = 0; j < n; j++) {
			ret += lower_bound(b.begin(), b.end(), a[j]) - b.begin();
		}
		cout << ret << '\n';
		a.clear();
		b.clear();
	}
	return 0;
}