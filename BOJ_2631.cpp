#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> children;
	int dp[201];
	int n;
	int maxNum = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		children.push_back(input);
	}

	// 답 = 전체 아이들의 수 - 아이들의 번호 수열에서 가장 긴 증가하는 수열의 길이
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (children[i] > children[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxNum = max(maxNum, dp[i]);
	}

	cout << n - maxNum;
	return 0;
}