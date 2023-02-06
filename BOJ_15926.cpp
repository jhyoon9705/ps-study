#include <bits/stdc++.h>
using namespace std;

int n, temp, ret;
string s;
stack<int> st;
int d[200002];

int main() {
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == '(') st.push(i);
		else if (st.size()) {
			d[i] = d[st.top()] = 1;
			st.pop();
		}
	}
	for (int i = 0; i < n; i++) {
		if (d[i] == 1) {
			temp++;
			ret = max(ret, temp);
		}
		else {
			temp = 0;
		}
	}
	cout << ret << "\n";
	return 0;
}