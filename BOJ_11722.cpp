#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int answer = 0;
	int arr[1000], dp[1000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1; // 수열의 최소 크기는 1
		for (int j = 0; j < i; j++) { // 수열의 맨 앞부터 i번째까지 비교
			if (arr[i] < arr[j]) { // 비교할 값이 바로 직전 값보다 작은 경우
				dp[i] = max(dp[i], dp[j] + 1); // 감소하는 부분 수열의 길이를 1 증가
			}
		}
		answer = max(answer, dp[i]); // 가장 긴 감소하는 부분 수열의 길이
	}

	cout << answer;
}