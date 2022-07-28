#include <bits/stdc++.h>

using namespace std;

int t, n;
int dp[10001];
vector<int> v;

int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		v.clear();
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int coin;
			cin >> coin;
			v.push_back(coin);
		}

		int value;
		cin >> value;

		for (int j = 0; j < (int)v.size(); j++) {
			int coinValue = v.at(j);
			for (int k = coinValue; k <= value; k++) {
				dp[k] = dp[k] + dp[k - coinValue]; 
				// ���������� ������ �ִ� ������ ��ġ��ŭ ���ϴ� ���̽��� �߰���
				// ex) k�� ����� ����� �� = k���� �� ������ ��ġ�� �� ���� ����� ����� ������ ��
			}
		}

		cout << dp[value] << '\n';
	}

	return 0;
}