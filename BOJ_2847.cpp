#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v;
	int n;
	int answer = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = (int)v.size() - 1; i >= 1; i--) {
		while (v[i - 1] >= v[i]) {
			v[i - 1] = v[i - 1] - 1;
			answer++;
		}
	}
	cout << answer;
	return 0;
}