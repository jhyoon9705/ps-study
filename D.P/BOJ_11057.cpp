#include <bits/stdc++.h>

using namespace std;

// i 길이의 j로 끝나는 오르막수의 개수를 저장
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
				// 길이가 i이면서 j로 끝나는 오르막수의 개수 
				// = 길이가 i-1이면서 j로 끝나는 오르막수 개수(맨 앞에 첫번째 수를 붙여서 길이를 i로 만들 수 있음) + 길이가 i면서 j-1로 끝나는 오르막수 개수
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