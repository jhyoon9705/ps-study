#include <bits/stdc++.h>

using namespace std;

int main() {
	string S, T;
	string temp;

	cin >> S;
	cin >> T;

	while (T.size() != S.size()) {
		if (T.back() == 'A') {
			T.pop_back();
		}
		else if (T.back() == 'B') {
			T.pop_back();

			temp.resize(T.size());
			copy(T.rbegin(), T.rend(), temp.begin());
			T = temp;
			temp.clear();
		}
	}

	if (S == T) cout << 1 << endl;
	else cout << 0 << endl;
}