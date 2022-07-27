// BOJ_2217 (https://www.acmicpc.net/problem/2217)
#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v, res;
	int n, w;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end());

	int iter = 0;
	for (int j = n; j >= 1; j--) {
		res.push_back(v[iter++] * j);
	}
	sort(res.begin(), res.end());

	int result = res.back();
	cout << result;

}