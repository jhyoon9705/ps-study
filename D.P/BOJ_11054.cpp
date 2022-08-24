#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001], dpInc[1001], dpDec[1001];
vector<int> num;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dpInc[i] = 1;
		dpDec[i] = 1;
	}

	// 앞에서부터 증가하는 수열의 최대 길이 구하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dpInc[i] = max(dpInc[j] + 1, dpInc[i]);
			}
		}
	}

	// 뒤에서부터 증가하는 수열의 최대 길이 구하기 
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				dpDec[i] = max(dpDec[j] + 1, dpDec[i]);
			}
		}
	}

	// 각 구간별 앞에서부터 증가하는 수열의 길이 + 그 뒤에서부터 뒤에서부터 감소하는 수열의 최대 길이
	for (int i = 0; i < n; i++) {
		int k = 1;
		while (arr[i] == arr[i + k]) { // 증가하는 수열의 마지막 수와 감소하는 수열의 첫번째 수가 같은 경우 빼주기
			k++;
		}
		int len = dpInc[i] + *max_element(dpDec + i + k, dpDec + n);
		if (*max_element(dpDec + i + k, dpDec + n) == arr[i]) {
			len -= 1;
		}
		num.push_back(len);
	}

	sort(num.begin(), num.end());
	cout << num[n - 1];

	return 0;
}