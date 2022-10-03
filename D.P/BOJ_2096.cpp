#include <bits/stdc++.h>

using namespace std;

int N;
int max_dp[3], min_dp[3], input[3], cache[3];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			int inputA, inputB, inputC;
			cin >> inputA >> inputB >> inputC;
			max_dp[0] = inputA;
			max_dp[1] = inputB;
			max_dp[2] = inputC;
			min_dp[0] = inputA;
			min_dp[1] = inputB;
			min_dp[2] = inputC;

		}
		else {
			cin >> input[0] >> input[1] >> input[2];

			cache[0] = max(max_dp[0] + input[0], max_dp[1] + input[0]);
			cache[1] = max(max(max_dp[0] + input[1], max_dp[1] + input[1]), max_dp[2] + input[1]);
			cache[2] = max(max_dp[1] + input[2], max_dp[2] + input[2]);
			max_dp[0] = cache[0];
			max_dp[1] = cache[1];
			max_dp[2] = cache[2];

			cache[0] = min(min_dp[0] + input[0], min_dp[1] + input[0]);
			cache[1] = min(min(min_dp[0] + input[1], min_dp[1] + input[1]), min_dp[2] + input[1]);
			cache[2] = min(min_dp[1] + input[2], min_dp[2] + input[2]);
			min_dp[0] = cache[0];
			min_dp[1] = cache[1];
			min_dp[2] = cache[2];
		}
	}

	long long maxAnswer = max(max(max_dp[0], max_dp[1]), max_dp[2]);
	long long minAnswer = min(min(min_dp[0], min_dp[1]), min_dp[2]);

	cout << maxAnswer << " " << minAnswer;
	return 0;
}