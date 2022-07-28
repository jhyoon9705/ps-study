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
				// 마지막으로 가지고 있는 동전의 가치만큼 더하는 케이스가 추가됨
				// ex) k를 만드는 방법의 수 = k에서 각 동전의 가치를 뺀 값을 만드는 방법의 수들의 합
			}
		}

		cout << dp[value] << '\n';
	}

	return 0;
}