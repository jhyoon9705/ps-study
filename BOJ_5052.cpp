#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<string> v;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		string ret = "YES";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n - 1; i++) {
			if (v[i].length() > v[i + 1].length()) continue;
			if (v[i] == v[i + 1].substr(0, v[i].length())) {
				ret = "NO";
				break;
			}
		}
		cout << ret << "\n";
		v.clear();
	}
	return 0;
}