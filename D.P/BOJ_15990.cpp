#include <bits/stdc++.h>
#define MOD 1000000009

using namespace std;

int T;
long long arr[100001][3];

int main() {
	cin >> T;

	arr[1][0] = 1;
	arr[2][1] = 1;
	arr[3][0] = 1;
	arr[3][1] = 1;
	arr[3][2] = 1;

	for (int i = 0; i < T; i++) {
		int number;
		cin >> number;

		for (int j = 4; j <= number; j++) {
			arr[j][0] = (arr[j - 1][1] + arr[j - 1][2]) % MOD;
			arr[j][1] = (arr[j - 2][0] + arr[j - 2][2]) % MOD;
			arr[j][2] = (arr[j - 3][0] + arr[j - 3][1]) % MOD;
		}
		cout << (arr[number][0] + arr[number][1] + arr[number][2]) % MOD << "\n";
	}
	return 0;
}