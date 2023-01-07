#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, result;
	bool checker = false;
	vector<int> v;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.rbegin(), v.rend());

	for (int i = 0; i <= n - 3; i++) {
		if (v[i] < v[i + 1] + v[i + 2]) {
			result = v[i] + v[i + 1] + v[i + 2];
			checker = true;
			break;
		}
	}

	if (checker) cout << result;
	else cout << -1;

	return 0;
}