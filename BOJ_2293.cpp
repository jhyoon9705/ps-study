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

	dp[0] = 1; // 아무것도 선택하지 않은 case도 1개의 case

	for (int i = 0; i < n; i++) {
		int value = v.at(i);
		
		for (int j = 1; j <= k; j++) {
			if (j - value >= 0) {
				dp[j] += dp[j - value]; // j를 만드는 방법의 수 += (j - 보유한 동전의 가치)의 case 수
			}
		}
	}

	cout << dp[k];
	return 0;
}