#include <bits/stdc++.h>
using namespace std;

string s;

bool check(string s) {
	stack<char> st;
	for (char c : s) {
		if (c == '(' || c == '[') st.push(c);
		else if (c == ')') {
			if (st.size() && st.top() == '(') st.pop();
			else return false;
		}
		else if (c == ']') {
			if (st.size() && st.top() == '[') st.pop();
			else return false;
		} 
	}
	return st.empty();
}

int main() {
	while (true) {
		getline(cin, s);
		if (s == ".") break;
		if (check(s)) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	return 0;
}
