#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[1000], dp[1000];
	int answer = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		answer = max(answer, dp[i]);
	}

	cout << answer;
}