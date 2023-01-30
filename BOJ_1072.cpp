#include <bits/stdc++.h>
using namespace std;

long long x, y, z, lo, hi = 1e9, mid, ret;
bool flag = false;

bool check(long long num) {
	long long px = x;
	long long py = y;
	if ((py + num) * 100 / (px + num) != z) return true;
	else return false;
}

int main() {
	cin >> x >> y;
	z = y * 100 / x;	
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) {
			flag = true;
			hi = mid - 1;
			ret = mid;
		}
		else lo = mid + 1;
	}
	if (flag) cout << ret << '\n';
	else cout << "-1" << '\n';
	return 0;
}