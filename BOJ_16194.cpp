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

	for (int i = 1; i <= n; i++) { // �� i���� ����
		dp[i] = card[i]; // i�� ���� ��, �� �ѿ� i�� ����ִ� ���� ����
		for (int j = 1; j <= i; j++) {
			// i�� ����ִ� ���� ���� or i-j�� ���� �ּ� ��� + j�� ����ִ� ���� ����
			dp[i] = min(dp[i], dp[i - j] + card[j]);
		}
	}

	cout << dp[n];

	return 0;
}