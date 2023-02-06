#include <bits/stdc++.h>
using namespace std;

int t, n;
string p, s, temp = "", ret = "";
char c;
deque<string> dq;

int main() {
	cin >> t;
	while (t--) {
		cin >> p;
		cin >> n;
		cin >> s;

		bool flag = false;
		temp = "";
		ret = "";
		dq.clear();

		for (int i = 1; i < s.length() - 1; i++) {
			if (s[i] != ',') temp += s[i];
			else {
				dq.push_back(temp);
				temp = "";
			}
		}
		if (temp != "") dq.push_back(temp);
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') {
				flag = !flag;
			}
			else {
				if (dq.size() == 0) {
					ret = "error";
					break;
				}
				if (flag) dq.pop_back();
				else dq.pop_front();
			}
		}
		if (ret.size()) cout << ret << "\n";
		else if (dq.size() == 0) {
			cout << "[]" << "\n";
		}
		else {
			cout << '[';
			int dqSize = dq.size();
			for (int i = 0; i < dqSize - 1; i++) {
				if (flag) {
					cout << dq.back() << ',';
					dq.pop_back();
				}
				else {
					cout << dq.front() << ',';
					dq.pop_front();
				}
			}
			cout <<  dq[0] << ']' << "\n";
		}		
	}
	return 0;
}