#include <bits/stdc++.h>
using namespace std;

int n, m, arr[5002], ret = 987654321;

bool check(int num) {
	int cnt = 1;
	int minNum = arr[0];
	int maxNum = arr[0];
	for (int i = 1; i < n; i++) {
		minNum = min(minNum, arr[i]);
		maxNum = max(maxNum, arr[i]);
		if ((maxNum - minNum) > num) {
			cnt++;
			minNum = arr[i];
			maxNum = arr[i];
		}
	}
	return cnt <= m;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int right = *max_element(arr, arr + 5002);
	int left = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			ret = min(ret, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ret << "\n";
	return 0;
}