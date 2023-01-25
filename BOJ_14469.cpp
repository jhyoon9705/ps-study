#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int n, a, b;
int ret = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int start = v[i].first;
		int t = v[i].second;
		if (ret <= start) ret = start + t;
		else ret += t;
	}
	cout << ret << '\n';
	return 0; 
}