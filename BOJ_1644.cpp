#include <bits/stdc++.h>
using namespace std;

bool prime[4000001];
int n, arr[2000001], lo, hi, ret, sum, p;

int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (prime[i]) continue;
		for (int j = 2 * i; j <= n; j += i) {
			prime[j] = 1;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (!prime[i]) arr[p++] = i;
	}
	while (true) {
		if (sum >= n) sum -= arr[lo++];
		else if (hi == p) break;
		else sum += arr[hi++];
		if (sum == n) ret++;
	}
	cout << ret << '\n';
	return 0;
}