// 0-1 knapsack
#include <bits/stdc++.h>

using namespace std;

int arr[101][100001] = { 0, };
int n, k;
vector<pair<int, int>> obj;

int main() {
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		obj.push_back({ w, v });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (obj.at(i - 1).first > j) {
				arr[i][j] = arr[i-1][j];
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - obj.at(i - 1).first] + obj.at(i - 1).second);
			}
		}
	}

	cout << arr[n][k];
	return 0;
}