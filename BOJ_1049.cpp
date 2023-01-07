#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	int answer = 0;
	vector<int> six, one;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		six.push_back(a);
		one.push_back(b);
	}
	sort(six.begin(), six.end());
	sort(one.begin(), one.end());

	if (six[0] < one[0] * 6) {
		while (n >= 6) {
			answer += six[0];
			n -= 6;
		}
	}
	else {
		while (n >= 6) {
			answer += (one[0] * 6);
			n -= 6;
		}
	}

	if (six[0] < one[0] * n) {
		answer += six[0];
	}
	else {
		answer += (one[0] * n);
	}

	cout << answer;
	return 0;
}