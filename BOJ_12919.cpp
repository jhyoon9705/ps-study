#include <bits/stdc++.h>
using namespace std;

string s, t, temp;
int ret = 0;

void solve(string st) {
	if (st.length() < s.length()) return;
	if (st == s) {
		ret = 1;
		return;
	}
	if (st[0] == 'A' && st[st.length() - 1] == 'A') {
		solve(st.substr(0, st.length() - 1));
	}
	else if (st[0] == 'A' && st[st.length() - 1] == 'B') {
		return;
	}
	else if (st[0] == 'B' && st[st.length() - 1] == 'A') {
		solve(st.substr(0, st.length() - 1));
		temp = st;
		reverse(st.begin() + 1, st.end());
		solve(st.substr(1, st.length()));
		st = temp;
	}
	else {
		temp = st;
		reverse(st.begin() + 1, st.end());
		solve(st.substr(1, st.length()));
		st = temp;
	}
}

int main() {
	cin >> s;
	cin >> t;
	solve(t);
	cout << ret << '\n';
	return 0;
}