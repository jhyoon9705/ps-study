#include <bits/stdc++.h>

using namespace std;

int main() {
	long long dp[65][10]; // ����� ���� int �ڷ����� �Ѿ
	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		fill(&dp[0][0], &dp[64][10], 1);
		cin >> n;
		
		for (int j = 2; j <= n; j++) {
			for (int k = 1; k < 10; k++) {
				dp[j][k] = dp[j][k - 1] + dp[j - 1][k];
			}
		}

		long long answer = 0; // ����� ���� int �ڷ����� �Ѿ

		for (int l = 0; l < 10; l++) {
			answer = answer + dp[n][l];
		}

		cout << answer << endl;
	}

	return 0;
}