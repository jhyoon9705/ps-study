#include <bits/stdc++.h>
using namespace std;

int h, w, k, ret;
int arr[501][501];

int main() {
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> k;
		for (int j = h; j >= h - k; j--) {
			arr[j][i] = 1;
		}
	}
	for (int i = 0; i < h; i++) {
		int l = -1, r = -1;
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 1) {
				if (l == -1) {
					l = j;
				}
				else {
					r = j;
					ret += (r - l) - 1;
					l = r;
					r = -1;
				}
			}
		}
	}
	cout << ret << "\n";
	return 0;
}