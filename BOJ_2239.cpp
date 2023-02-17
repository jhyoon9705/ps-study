#include <bits/stdc++.h>
using namespace std;

int sdk[9][9];
string s;
bool isFinish = false;

void solve(int cnt) {
	if (isFinish) return;
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sdk[i][j];
			}
			cout << "\n";
			isFinish = true;
		}
		return;
	}

	int y = cnt / 9;
	int x = cnt % 9;
	if (sdk[y][x] != 0) solve(cnt + 1);
	else {
		for (int i = 1; i <= 9; i++) {
			bool isAvail = true;
			for (int j = 0; j < 9; j++) {
				if (sdk[y][j] == i || sdk[j][x] == i) {
					isAvail = false;
					break;
				}
			}
			if (!isAvail) continue;
			int ny = (y / 3) * 3;
			int nx = (x / 3) * 3;
			for (int j = ny; j < ny + 3; j++) {
				for (int k = nx; k < nx + 3; k++) {
					if (sdk[j][k] == i) {
						isAvail = false;
						break;
					}
				}
				if (!isAvail) break;
			}
			if (isAvail) {
				sdk[y][x] = i;
				solve(cnt + 1);
				sdk[y][x] = 0;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> s;
		for (int j = 0; j < 9; j++) {
			sdk[i][j] = s[j] - '0';
		}
	}
	solve(0);
	return 0;
}