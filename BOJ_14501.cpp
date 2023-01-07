#include <bits/stdc++.h>

using namespace std;

int T[20], P[20], dp[20];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (j + T[j] <= i && i + T[i] <= n + 1) {
				dp[i] = max(dp[i], dp[j] + P[i]);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i <= n; i++) {
		answer = max(answer, dp[i]);
	}

	cout << answer;
}