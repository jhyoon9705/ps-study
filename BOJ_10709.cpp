#include <bits/stdc++.h>
using namespace std;

int h, w;
char arr[101][101];
int ret[101][101];

int main() {
	memset(ret, -1, sizeof(ret));
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 'c') {
				ret[i][j] = 0; 
				continue;
			}
			for (int k = j - 1; k >= 0; k--) {
				if (arr[i][k] == 'c') {
					ret[i][j] = j - k;
					break;
				}
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ret[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}