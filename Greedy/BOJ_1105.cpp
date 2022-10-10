#include <bits/stdc++.h>

using namespace std;

int main() {
	int answer = 0;
	string L, R;
	cin >> L >> R;

	if (L.length() != R.length()) {
		answer = 0;
	}
	else {
		for (int i = 0; i < L.length(); i++) {
			if (L[i] != R[i]) {
				break;
			}
			if (L[i] == '8' && R[i] == '8') {
				answer++;
			}
		}
	}

	cout << answer;
	return 0;
}