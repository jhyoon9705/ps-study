#include <bits/stdc++.h>
using namespace std;

int t, w, ret;
int arr[1002], dp[1004][2][34];
int prevPos = 1;

int solve(int idx, int myPos, int cnt) {
	if (cnt < 0) return -1e9;
	if (idx == t) return 0;
	int& ret = dp[idx][myPos][cnt];
	if (~ret) return ret;
	return ret = max(solve(idx + 1, myPos ^ 1, cnt - 1), solve(idx + 1, myPos, cnt)) + (myPos == arr[idx] - 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> t >> w;
	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}
	cout << max(solve(0, 1, w - 1), solve(0, 0, w)) << "\n";
	return 0;
}