// BOJ_12015¿Í µ¿ÀÏ
#include <bits/stdc++.h>
using namespace std;

int n;
long long input, ret = 1;
long long arr[1000002];

int main() {
	cin >> n;
	cin >> arr[1];
	for (int i = 2; i <= n; i++) {
		cin >> input;
		if (arr[ret] < input) arr[++ret] = input;
		else {
			auto p = lower_bound(arr + 1, arr + ret, input);
			*p = input;
		}
	}
	cout << ret << '\n';
	return 0;
}