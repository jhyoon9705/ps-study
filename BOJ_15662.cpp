#include <bits/stdc++.h>
using namespace std;

int t, k, ret;
char a[1002][8];

void leftRotate(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		int tNum = v[i];
		int leftEnd = a[tNum][0];
		for (int i = 1; i < 8; i++) {
			a[tNum][i - 1] = a[tNum][i];
		}
		a[tNum][7] = leftEnd;
	}
}

void rightRotate(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		int tNum = v[i];
		int rightEnd = a[tNum][7];
		for (int i = 7; i >= 1; i--) {
			a[tNum][i] = a[tNum][i - 1];
		}
		a[tNum][0] = rightEnd;
	}
}

int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> a[i][j];
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int num, dir;
		cin >> num >> dir;
		
		vector<int> lr, rr;
		if (dir == 1) rr.push_back(num);
		else lr.push_back(num);
		int prevDir = dir;
		for (int j = num; j > 1; j--) {
			if (a[j][6] != a[j - 1][2]) {
				if (prevDir == -1) {
					rr.push_back(j - 1);
					prevDir = 1;
				}
				else if (prevDir == 1) {
					lr.push_back(j - 1);
					prevDir = -1;
				}
			}
			else break;
		}

		prevDir = dir;
		for (int j = num; j <= t - 1 ; j++) {
			if (a[j][2] != a[j + 1][6]) {
				if (prevDir == -1) {
					rr.push_back(j + 1);
					prevDir = 1;
				}
				else if (prevDir == 1) {
					lr.push_back(j + 1);
					prevDir = -1;
				}
			}
			else break;
		}
		leftRotate(lr);
		rightRotate(rr);
	}
	
	for (int i = 1; i <= t; i++) {
		if (a[i][0] == '1') ret++;
	}
	cout << ret << '\n';
	return 0;
}