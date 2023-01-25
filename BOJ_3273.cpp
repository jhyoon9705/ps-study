#include <bits/stdc++.h>
using namespace std;

int n, x, ret, l, r;
vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	cin >> x;
	sort(v.begin(), v.end());
	l = 0;
	r = n - 1;
	while (l < r) {
		if (v[l] + v[r] == x) {
			r--;
			ret++;
		}
		else if (v[l] + v[r] > x) r--;
		else if (v[l] + v[l] < x) l++;
	}
	cout << ret << '\n';
	return 0;
}