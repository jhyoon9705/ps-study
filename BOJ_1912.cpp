// 직전까지의 연속 합 최대 + 해당 인덱스 자신 or 해당 인덱스 자신 중 큰 것으로 선택
#include <bits/stdc++.h>

using namespace std;

int main() {
	int arr[100000];
	int dp[100000];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int maxNum = dp[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		maxNum = max(maxNum, dp[i]);
	}

	cout << maxNum;
}