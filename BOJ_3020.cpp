#include <bits/stdc++.h>
using namespace std;

int n, h, input, lo, hi, mid;
int top[500001], bottom[500001];

int main() {
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (i % 2 == 0) bottom[input]++;
		else top[h - input + 1]++;
	}
	for (int i = 1; i <= h; i++) {
		top[i] += top[i - 1];
		bottom[h - i] += bottom[h - i + 1];
	}
	long long ret = 1e13 + 7;
	int cnt = 0;
	for (int i = 1; i <= h; i++) {
		if (top[i] + bottom[i] < ret) {
			cnt = 1;
			ret = top[i] + bottom[i];
		}
		else if (top[i] + bottom[i] == ret) {
			cnt++;
		}
	}
	cout << ret << " " << cnt << "\n";
	return 0;
}