#include <bits/stdc++.h>

using namespace std;

int arr[1001], dp[1001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i]; // 항이 1개인 수열의 합은 자기 자신
	}

	int answer = dp[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[j] + arr[i], dp[i]);
			}
		}
		answer = max(answer, dp[i]);
	}

	cout << answer;
}