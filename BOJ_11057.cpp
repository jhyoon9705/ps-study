#include <bits/stdc++.h>

using namespace std;

// i ������ j�� ������ ���������� ������ ����
int dp[1001][10];

int main() {
	int answer = 0;
	int n;
	cin >> n;

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 2;  i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j != 0) {
				// ���̰� i�̸鼭 j�� ������ ���������� ���� 
				// = ���̰� i-1�̸鼭 j�� ������ �������� ����(�� �տ� ù��° ���� �ٿ��� ���̸� i�� ���� �� ����) + ���̰� i�鼭 j-1�� ������ �������� ����
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				dp[i][j] %= 10007;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		answer += dp[n][i];
		answer %= 10007;
	}

	cout << answer;

}