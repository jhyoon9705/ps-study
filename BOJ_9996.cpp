#include <bits/stdc++.h>
using namespace std;

int N;
string pattern, s;
string pref, suff;
int starIndex = 0;

void solve(string str) {
	if (pref.size() + suff.size() <= str.size()) {
		if (pref == str.substr(0, pref.size()) && suff == str.substr(str.size() - suff.size())) cout << "DA" << '\n';
		else cout << "NE" << '\n';
	}
	else cout << "NE" << '\n';
}

int main() {
	cin >> N;
	cin >> pattern;

	for (char c : pattern) {
		if (c != '*') starIndex++;
		else break;
	}

	pref = pattern.substr(0, starIndex);
	suff = pattern.substr(starIndex + 1);
	
	for (int i = 0; i < N; i++) {
		cin >> s;
		solve(s);
	}
	return 0;
}