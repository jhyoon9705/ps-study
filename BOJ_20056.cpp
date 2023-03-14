#include <bits/stdc++.h>
using namespace std;

struct Fireball{
	int m, s, d;
};
int i1, i2, i3, i4, i5, ret;
vector<Fireball> arr[52][52];
const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int n, m, k;

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> i1 >> i2 >> i3 >> i4 >> i5;
		arr[i1 - 1][i2 - 1].push_back({ i3, i4, i5 });
	}
	for (int c = 0; c < k; c++) {
		vector<Fireball> temp[52][52];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (Fireball f : arr[i][j]) {
					int dir = f.d;
					int speed = f.s;
					int nRow = (i + (dy[dir] * speed)) % n;
					int nCol = (j + (dx[dir] * speed)) % n;
					if (nRow < 0) nRow += n;
					if (nCol < 0) nCol += n;
					temp[nRow][nCol].push_back({ f.m, speed, dir });
				}
 			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (temp[i][j].size() > 1) {
					int totalM = 0;
					int totalS = 0;
					bool isOdd = false;
					bool isEven = false;
					for (Fireball f : temp[i][j]) {
						if (f.d % 2 == 0) isEven = true;
						else isOdd = true;
						totalM += f.m;
						totalS += f.s;
					}					
					int thisM = totalM / 5;
					int thisS = totalS / temp[i][j].size();
					temp[i][j].clear();
					if (thisM == 0) continue;					
					if (isEven && isOdd) {
						for (int k = 1; k <= 7; k += 2) {
							temp[i][j].push_back({ thisM, thisS, k });
						}
					}
					else {
						for (int k = 0; k <= 6; k += 2) {
							temp[i][j].push_back({ thisM, thisS, k });
						}
					}

				}
			}
		}
		copy(&temp[0][0], &temp[0][0] + 52 * 52, &arr[0][0]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (Fireball f : arr[i][j]) {
				ret += f.m;
			}
		}
	}
	cout << ret << "\n";
	return 0;
}