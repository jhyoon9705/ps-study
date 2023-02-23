#include <bits/stdc++.h>
using namespace std;

int n, height;
stack<pair<int, int>> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> height;
		if (st.empty()) {
			cout << '0' << " ";
			st.push({ i, height });
			continue;
		}
		while (!st.empty() && st.top().second < height) {
			st.pop();
		}
		if (st.empty()) {
			cout << '0' << " ";
			st.push({ i, height });
		}
		else {
			cout << st.top().first << " ";
			st.push({ i, height });
		}
	}
	return 0;
}