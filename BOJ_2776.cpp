#include <bits/stdc++.h>
using namespace std;

int t, n, m, input;

int check(int temp, vector<int>& v) {
	int lo = 0;
	int hi = v.size() - 1;
	int mid;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (v[mid] > temp) hi = mid - 1;
		else if (v[mid] == temp) return 1;
		else lo = mid + 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		vector<int> a;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> input;
			a.push_back(input);
		}
		sort(a.begin(), a.end());

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> input;
			cout << check(input, a) << '\n';
		}
	}
	return 0;
}