#include <bits/stdc++.h>

using namespace std;

int main() {
	int arr[10001], dp[10001];
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		// i��° ���� ���ð� + max(i-2��° �ܱ����� �ִ� or i-1��° �ܵ� ���ð� i-2��° ���� ������ �ʰ� i-3��° �ܱ����� �ִ�
		dp[i] = arr[i] + max(dp[i - 2], arr[i - 1] + dp[i - 3]);

		// �� ���� �������� ������ �ʾ��� ��쵵 ���
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[n];
}