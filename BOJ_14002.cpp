#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1001], dp[1001], series[1001];
vector<int> v;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
		series[i] = i;
	}

	// ���� �� ���� ���� ���ϱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
							
			}
		}
	}

	// ���� �� ���� ������ ����
	int maxNum = *max_element(dp, dp + N);

	// �迭�� �ڿ������� dp �迭�� �����ϴ� ������ vector�� push_back
	for (int i = max_element(dp, dp + N) - dp; i >= 0; i--) {
		if (dp[i] == maxNum) {
			v.push_back(arr[i]);
			maxNum--;
		}
	}
	
	cout << *max_element(dp, dp + N) << "\n";

	// vector�� �ڿ������� ���
	for (int i = (int)v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
	return 0;

}