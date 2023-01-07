#include <bits/stdc++.h>
using namespace std;

int box[1001], dp[1001];

int main() {
	int n, answer = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (box[i] > box[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				answer = max(dp[i], answer);
			}
		}
	}

	cout << answer + 1;
}