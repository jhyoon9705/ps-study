#include <bits/stdc++.h>
using namespace std;

int n, input, ret = 1, arr[100002];

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
	cout << n - ret << "\n";
	return 0;
}