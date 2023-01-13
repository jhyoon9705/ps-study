#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
string input;
string ret;

void solve() {
	while (1) {
		if (ret.size() && ret.front() == '0') ret.erase(ret.begin());
		else break;
	}
	if (ret.size() == 0) ret = "0";
	v.push_back(ret);
	ret = "";
}

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		ret = "";
		for (int j = 0; j < input.size(); j++) {
			if (input[j] < 65) ret += input[j];
			else if (ret.size()) solve();
		}
		if (ret.size()) solve();
	}
	sort(v.begin(), v.end(), cmp);
	for (string i : v) cout << i << '\n';
	return 0;
}