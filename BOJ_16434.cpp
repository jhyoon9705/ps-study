#include <bits/stdc++.h>
using namespace std;

long long n, hAtk, ti, ai, hi, tempH;
struct A {
	long long t, a, h;
};
vector<A> v;
long long l, r = 1e18 + 4, mid, ret, myHp;

bool check(long long hp) {
	myHp = hp;
	for (int i = 0; i < n; i++) {
		A temp = v[i];
		if (temp.t == 1) {
			long long div = temp.h / hAtk + (temp.h % hAtk ? 1 : 0);
			long long atk_cnt = div - 1;
			myHp -= atk_cnt * temp.a;
		}
		else if (temp.t == 2) {
			hAtk += temp.a;
			myHp += temp.h;
			if (myHp > hp) myHp = hp;
		}
		if (myHp <= 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> hAtk;
	tempH = hAtk;
	for (int i = 0; i < n; i++) {
		cin >> ti >> ai >> hi;
		v.push_back({ ti, ai, hi });
	}

	while (l <= r) {
		mid = (l + r) / 2;
		hAtk = tempH;
		if (check(mid)) {
			ret = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ret << '\n';
	return 0;
}