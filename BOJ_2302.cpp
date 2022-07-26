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

	// VIP���� �������� �������� �ش� �¼� ����ŭ�� ����� ��(dp �迭)�� ���ؼ� ���� 
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