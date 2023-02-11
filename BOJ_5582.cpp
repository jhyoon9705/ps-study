#include <bits/stdc++.h>
using namespace std;

string a, b;
int arr[4002][4002], ret;

int main() {
	cin >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i] >= 'A' && a[i] <= 'Z' && a[i] == b[j]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				ret = max(ret, arr[i][j]);
			}
		}
	}
	cout << ret << "\n";
	return 0;
}