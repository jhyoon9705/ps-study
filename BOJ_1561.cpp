#include <bits/stdc++.h>
using namespace std;

long long n, m, input, lo = 1, hi = 60000000004, mid, ret, temp;
vector<long long> v;

bool check(long long num) {
	temp = m;
	for (int i = 0; i < m; i++) {
		temp += num / v[i];
	}
	return temp >= n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		v.push_back(input);
	}
	if (n <= m) {
		cout << n << '\n';
		return 0;
	}
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) {
			hi = mid - 1;			
			ret = mid;
		}
		else {
			lo = mid + 1;
		}
	}

	temp = m;
	for (int i = 0; i < m; i++) {
		temp += ((ret - 1) / v[i]);
	}
	for (int i = 0; i < m; i++) {
		if (ret % v[i] == 0) temp++;
		if (temp == n) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
	return 0;
}