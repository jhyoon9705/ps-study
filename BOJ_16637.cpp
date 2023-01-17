#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321;
string s;
vector<char> op;
vector<int> num;

int oper(int a, int b, char c) {
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else return a * b;
}

void solve(int here, int n) {
	if (here == num.size() - 1) {
		ret = max(ret, n);
		return;
	}
	solve(here + 1, oper(n, num[here + 1], op[here]));
	if (here + 2 <= num.size() - 1) {
		int temp = oper(num[here + 1], num[here + 2], op[here + 1]);
		solve(here + 2, oper(n, temp, op[here]));
	}
	return;
}

int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else op.push_back(s[i]);
	}
	solve(0, num[0]);
	cout << ret << '\n';
	return 0;
}
