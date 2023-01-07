#include <bits/stdc++.h>

using namespace std;

int house[1001][3];

int main(void) {
	int n;
	cin >> n;

	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;
	int cost[3];

	for (int i = 1; i <= n; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		// 이전 집까지의 비용 최솟값과 RGB 각 비용의 합을 memoization
		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0];
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + cost[2];
	}

	// n번째까지 색칠하였을 때, 비용의 최솟값을 출력
	cout << min(house[n][0], min(house[n][1], house[n][2]));
}