#include <bits/stdc++.h>

using namespace std;

long long answer = 1;
int dp[41];
queue<int> q;

int main() {
	int n, m;
	cin >> n >> m;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		q.push(input);
	}

	q.push(n + 1);

	// VIP석을 기준으로 나누어진 해당 좌석 수만큼의 경우의 수(dp 배열)를 구해서 곱함 
	int range, prevFixed = 0;
	while (!q.empty()) {
		int fixed = q.front();
		q.pop();
		range = fixed - prevFixed - 1;
		prevFixed = fixed;

		answer *= dp[range];

	}
	cout << answer;

	return 0;
}