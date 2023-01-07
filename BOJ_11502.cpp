// ex) ī�带 4�� �� ���� �ִ���
// 1. ī�� 3�� �� ���� �ִ� + 1�� ī���� ��
// 2. ī�� 2�� �� ���� �ִ� + 2�� ī���� ��
// 3. ī�� 1�� �� ���� �ִ� + 3�� ī���� ��
// 4. ī�� 0�� �� ���� �ִ�(0) + 4�� ī���� ��
// �� �ִ�

#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int card[1001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}

	cout << dp[n];

	return 0;
}