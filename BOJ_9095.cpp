#include <bits/stdc++.h>

using namespace std;

// ex) 4�� ����� ����� ��
// = 1���� 3�� ���� ��� + 2���� 2�� ���� ��� + 3���� 1�� ���� ���

int dp[11];

int main() {
	int t, n;
	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (t--) {
		cin >> n;
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}
		cout << dp[n] << endl;
	}
	return 0;
}