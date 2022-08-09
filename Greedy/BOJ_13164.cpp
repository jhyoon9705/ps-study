#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> height, diff;
	int answer = 0;
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		height.push_back(input);
	}

	// 이웃한 원생들의 키 차이를 모두 구함
	for (int i = 0; i < n - 1; i++) {
		diff.push_back(height.at(i + 1) - height.at(i));
	}

	// 키 차이를 오름차순으로 정렬
	sort(diff.begin(), diff.end());

	// k개의 조로 나누면 k-1개의 키 차이는 다른 조로 나누면 되기 때문에 고려하지 않아도 됨
	for (int i = 0; i < n - k; i++) {
		answer += diff.at(i);
	}
	cout << answer;
	
	return 0;
}