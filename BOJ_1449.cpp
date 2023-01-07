// BOJ_1449 (https://www.acmicpc.net/problem/1449)
#include <bits/stdc++.h>

using namespace std;

int n, l, spot;
int result = 1;
vector<int> v;

int main() {
	cin >> n >> l;
	
	for (int i = 0; i < n; i++) {
		cin >> spot;
		v.push_back(spot);
	}
	sort(v.begin(), v.end());
	int start = v[0];

	for (int j = 1; j < n; j++) {
		if (v[j] - start + 1 > l) {
			result++;
			start = v[j];
		}

	}
	cout << result;

}