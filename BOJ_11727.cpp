#include <bits/stdc++.h>

using namespace std;

int dp[1001];

int main() {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		// n-1 �������� �����ʿ� 2*1 ������ �ϳ� ���� ���� �Ǵ�
		// n-2 �������� �����ʿ� 1*2 ���� ������ 2�� ���� ����, 2*2 ������ �ϳ� ���� ����
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}
	cout << dp[n];

	return 0;
}