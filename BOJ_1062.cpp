#include <bits/stdc++.h>
using namespace std;

int n, k, ret;
string s;
int arr[52];

int count(int mask) {
	int cnt = 0;
	for (int word : arr) {
		if (word && (word & mask) == word) cnt++;
	}
	return cnt;
}

int solve(int idx, int num, int mask) {
	if (num < 0) return 0;
	if (idx == 26) return count(mask);
	int ret = solve(idx + 1, num - 1, mask | (1 << idx)); // 배우는 case
	if (idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && idx != 'c' - 'a') {
		ret = max(ret, solve(idx + 1, num, mask)); // 배우지 않아도 되는 case
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (char str : s) {
			arr[i] |= (1 << (str - 'a'));
		}
		
	}
	cout << solve(0, k, 0) << "\n";
	return 0;	
}