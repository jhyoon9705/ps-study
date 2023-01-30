#include <bits/stdc++.h>
using namespace std;

long long s, c, input;
long long lo = 1, hi, mid, ret, total;
vector<long long> v;

bool check(long long num) {
	long long cnt = 0;
	for (int i = 0; i < s; i++) {
		long long temp = v[i];
		cnt += temp / num;
	}
	if (cnt >= c) return true;
	else return false;
}

int main() {
	cin >> s >> c;
	for (int i = 0; i < s; i++) {
		cin >> input;
		v.push_back(input);
		hi += input;
	}
	total = hi;

	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) {
			lo = mid + 1;
			ret = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << total - (ret * c) << '\n';
	return 0;
}