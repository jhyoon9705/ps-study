#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int answer = 0;
	int arr[1000], dp[1000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1; // ������ �ּ� ũ��� 1
		for (int j = 0; j < i; j++) { // ������ �� �պ��� i��°���� ��
			if (arr[i] < arr[j]) { // ���� ���� �ٷ� ���� ������ ���� ���
				dp[i] = max(dp[i], dp[j] + 1); // �����ϴ� �κ� ������ ���̸� 1 ����
			}
		}
		answer = max(answer, dp[i]); // ���� �� �����ϴ� �κ� ������ ����
	}

	cout << answer;
}