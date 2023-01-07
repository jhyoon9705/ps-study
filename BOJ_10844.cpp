#include <bits/stdc++.h>

using namespace std;

// i행 j열 배열
// i자리 계단 수 중에 j로 끝나는 계단 수의 개수: dp[i][j]에 저장
int dp[100][10];

int main() {
	int n;
	long long answer = 0;
	cin >> n;

	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1]; // 0으로 끝나는 i자리 계단수의 개수 = 1로 끝나는 i-1자리 계단수의 개수
		dp[i][9] = dp[i - 1][8]; // 9로 끝나는 i자리 계단수의 개수 = 8로 끝나는 i-1자리 계단수의 개수

		for (int j = 1; j <= 8; j++) {
			// 나머지 숫자(j)들로 끝나는 i자리 계단수의 개수 = j-1로 끝나는 i-1자리 계단수의 개수 + j+1로 끝나는 i-1자리 계단수의 개수
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) {
		answer += dp[n][i];
	}

	cout << answer % 1000000000;
	return 0;
}