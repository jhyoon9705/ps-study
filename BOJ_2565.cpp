#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<pair<int, int>> line;
	int n, answer;
	int dp[101];
	int maxNum = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		line.push_back({ a, b });
	}

	sort(line.begin(), line.end()); // A�� �������� ����

	// ���� �� �����ϴ� �κ� ������ ���ϴ� ����
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (line[i].second > line[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxNum = max(maxNum, dp[i]);
	}
	answer = n - maxNum;
	cout << answer;

	return 0;
}