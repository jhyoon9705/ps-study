#include <bits/stdc++.h>
using namespace std;

// ����(stack)
string s, s2, ret;
stack<char> stk;
int main() {
	cin >> s >> s2;
	for (char c : s) {
		stk.push(c);
		if (stk.size() >= s2.size() && stk.top() == s2[stk.size() - 1]) {
			string ss = "";
			for (char i : s2) {
				ss += stk.top();
				stk.pop();
			}
			reverse(ss.begin(), ss.end());
			if (s2 != ss) {
				for (int i : ss) {
					stk.push(i);
				}
			}
		}
	}
}

/* ����(pivot algorithm)
string s, s2, ret;
int main() {
	cin >> s >> s2;
	for (char a : s) {
		ret += a;
		if (ret.size() >= s2.size() && ret.substr(ret.size() - s2.size(), s2.size()) == s2) {
			ret.erase(ret.end() - s2.size(), ret.end());
		}
	}
	if (!ret.size()) cout << "FRULA" << '\n';
	else cout << ret << '\n';
	return 0;
} */

/* ����(�ð� �ʰ�)
string s, s2;
int main() {
	cin >> s;
	cin >> s2;

	long long pos = 0;

	while ((pos = s.find(s2)) != string::npos) {
		s.erase(pos, s2.length());
	}
	if (s.length()) cout << s << '\n';
	else cout << "FRULA" << '\n';

	return 0;
} */