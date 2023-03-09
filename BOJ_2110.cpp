#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> house;

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		house.push_back(input);
	}
	sort(house.begin(), house.end());

	int start = 1;
	int end = house[n - 1] - house[0];
	int ret = 0;

	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 1;
		int prev_house = house[0];
		for (int i = 1; i < n; i++) {
			if (house[i] - prev_house >= mid) {
				cnt++;
				prev_house = house[i];
			}
		}
		// 공유기를 제한 개수 이상 사용한 경우, 공유기를 설치하는 거리를 늘림
		if (cnt >= c) {
			ret = max(ret, mid);
			start = mid + 1;
		}
		// 공유기를 제한 개수 미만 사용한 경우, 공유기를 설치하는 거리를 줄임
		else end = mid - 1;
	}
	cout << ret << "\n";
	return 0;
}