#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m, k, ret = INF, tempRet;
int org[52][52], a[52][52], temp[52][52];
vector<int> order;
struct Oper {
	int _r, _c, _s;
};
Oper ops[7];

int findValue() {
	tempRet = INF;
	for (int i = 1; i <= n; i++) {
		int _val = 0;
		for (int j = 1; j <= m; j++) {
			_val += a[i][j];
		}
		tempRet = min(tempRet, _val);
	}
	return tempRet;
}

void solve(int row, int col, int _size) {
	copy(&a[0][0], &a[0][0] + (52 * 52), &temp[0][0]);
	for (int i = 1; i <= _size; i++) {
		for (int j = col + i; j > col - i; j--) {
			temp[row - i][j] = a[row - i][j - 1];
		}
		for (int j = col - i; j < col + i; j++) {
			temp[row + i][j] = a[row + i][j + 1];
		}
		for (int j = row - i; j < row + i; j++) {
			temp[j][col - i] = a[j + 1][col - i];
		}
		for (int j = row + i; j > row - i; j--) {
			temp[j][col + i] = a[j - 1][col + i];
		}
	}
	for (int j = 1; j <= n; j++) {
		for (int k = 1; k <= m; k++) {
			a[j][k] = temp[j][k];
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> org[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		order.push_back(i);
		int r, c, s;
		cin >> r >> c >> s;
		ops[i] = { r, c, s };
	}
	do {
		copy(&org[0][0], &org[0][0] + (52 * 52), &a[0][0]);
		for (int i = 0; i < k; i++) {
			solve(ops[order[i]]._r, ops[order[i]]._c, ops[order[i]]._s);
		}
		ret = min(ret, findValue());
	} while (next_permutation(order.begin(), order.end()));
	
	cout << ret << "\n";
	return 0;
}