#include <bits/stdc++.h>
using namespace std;

int r, c, m, ret;
int aa, bb, cc, dd, ee;
const int dx[5] = { 0, 0, 0, 1, -1 };
const int dy[5] = { 0, -1, 1, 0, 0 };
struct Shark {
	int sp, dir, sz;
};
vector<Shark> arr[101][101], temp[101][101];
vector<Shark> v;

void tempCopy() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] = temp[i][j];
			temp[i][j].clear();
		}
	}
}

int changeDir(int num) {
	if (num == 1) return 2;
	else if (num == 2) return 1;
	else if (num == 3) return 4;
	else return 3;
}

void fishing(int f) {
	for (int i = 0; i < r; i++) {
		if (arr[i][f].size()) {
			ret += (arr[i][f])[0].sz;
			arr[i][f].clear();
			break;
		}
	}
}

void moving() {	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j].size()) {
				Shark sh = (arr[i][j])[0];
				int _sp = sh.sp;
				int _dir = sh.dir;
				int _sz = sh.sz;
				int pR = i;
				int pC = j;
				if ((_dir == 1 && pR == 0) || (_dir == 2 && pR == r - 1) || (_dir == 3 && pC == c - 1) || (_dir == 4 && pC == 0)) {
					_dir = changeDir(_dir);
				}
				for (int k = 0; k < _sp; k++) {
					pR += dy[_dir];
					pC += dx[_dir];		
					if (((_dir == 1 || _dir == 2) && (pR == 0 || pR == r - 1)) || ((_dir == 3 || _dir == 4) && (pC == 0 || pC == c - 1))) {
						_dir = changeDir(_dir);
					}
				}
				if (temp[pR][pC].size()) {
					if ((temp[pR][pC])[0].sz < _sz) {
						(temp[pR][pC])[0] = { _sp, _dir, _sz };
					}
				}
				else temp[pR][pC].push_back({ _sp, _dir, _sz });
			}
		}
	}
	tempCopy();
}

int main() {
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		cin >> aa >> bb >> cc >> dd >> ee;
		if (dd <= 2) cc %= (r - 1) * 2;
		else cc %= (c - 1) * 2;
		arr[aa - 1][bb - 1].push_back({ cc, dd, ee });
	}
	for (int fisher = 0; fisher < c; fisher++) {
		fishing(fisher);
		moving();
	}	
	cout << ret << '\n';
	return 0;
}