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

	// �� = ��ü ���̵��� �� - ���̵��� ��ȣ �������� ���� �� �����ϴ� ������ ����
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