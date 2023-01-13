#include <bits/stdc++.h>
using namespace std;

int t;
string input;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		stack<char> st;
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			if (st.empty()) {
				st.push(input[j]);
				continue;
			}
			if (st.top() == '(' && input[j] == ')') st.pop();
			else st.push(input[j]);
		}
		if (st.empty()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}