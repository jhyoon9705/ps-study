#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int arr[11][11], ret = INF;
map<int, int> mp;

bool check(int y, int x, int cnt) {
	if (y + cnt > 10 || x + cnt > 10) return false;
	for (int i = y; i < y + cnt; i++) {
		for (int j = x; j < x + cnt; j++) {
			if (arr[i][j] == 0) return false;
		}
	}
	return true;
}

void draw(int y, int x, int cnt, int value) {
	for (int i = y; i < y + cnt; i++) {
		for (int j = x; j < x + cnt; j++) {
			arr[i][j] = value;
		}
	}
}

void dfs(int y, int x, int cnt) {
	if (cnt >= ret) return;
	if (x == 10) {
		dfs(y + 1, 0, cnt);
	}
	if (y == 10) {
		ret = min(cnt, ret);
		return;
	}
	if (arr[y][x] == 0) {
		dfs(y, x + 1, cnt);
		return;
	}
	for (int _size = 5; _size >= 1; _size--) {
		if (mp[_size] == 5) continue;
		if (check(y, x, _size)) {
			mp[_size]++;
			draw(y, x, _size, 0); // ∫Ÿ¿Ã±‚
			dfs(y, x + _size, cnt + 1);
			draw(y, x, _size, 1); // ∂º±‚(back-tracking)
			mp[_size]--;
		}
	}
	return;
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0, 0);
	cout << (ret == INF ? -1 : ret) << "\n";
	return 0;
}