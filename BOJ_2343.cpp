#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100002];
int lo, hi, mid, ret = 987654321;

bool check(int cap) {
	int cnt = 1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + arr[i] <= cap) {
			sum += arr[i];
		}
		else {
			cnt++;
			i--;
			sum = 0;
		}
		if (cnt > m) return false;
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		hi += arr[i];
	}
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) {
			ret = min(ret, mid);
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ret << '\n';
	return 0;
}