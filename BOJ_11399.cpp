// BOJ_11399 (https://www.acmicpc.net/problem/11399)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, p;
	int result = 0;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		v.push_back(p);
	}
	sort(v.begin(), v.end());

	for (int j = 0; j < n; j++) {
		result += v[j] + v[j] * (n - 1 - j);
	}

	cout << result;
}