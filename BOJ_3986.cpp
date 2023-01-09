#include <bits/stdc++.h>
using namespace std;

int N;
int ret = 0;
string input;


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<char> v;
		cin >> input;
		for (char c : input) {
			if (v.empty()) v.push_back(c);
			else {
				if (v[v.size() - 1] == c) v.pop_back();
				else v.push_back(c);
			}
		}
		if (v.empty()) ret++;
	}
	cout << ret << '\n';
	return 0;
}