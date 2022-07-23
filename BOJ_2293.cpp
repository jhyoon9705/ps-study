#include <bits/stdc++.h>

using namespace std;

int dp[100001];
vector<int> v;

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	dp[0] = 1; // �ƹ��͵� �������� ���� case�� 1���� case

	for (int i = 0; i < n; i++) {
		int value = v.at(i);
		
		for (int j = 1; j <= k; j++) {
			if (j - value >= 0) {
				dp[j] += dp[j - value]; // j�� ����� ����� �� += (j - ������ ������ ��ġ)�� case ��
			}
		}
	}

	cout << dp[k];
	return 0;
}