#include <bits/stdc++.h>
using namespace std;

int N;
char arr[65][65];
string s;

string solve(int y, int x, int size) {
	if (size == 1) return string(1, arr[y][x]);
	char c = arr[y][x];
	string ret = "";

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (c != arr[i][j]) {
				ret += '(';
				ret += solve(y, x, size / 2);
				ret += solve(y, x + size / 2, size / 2);
				ret += solve(y + size / 2, x, size / 2);
				ret += solve(y + size / 2, x + size / 2, size / 2);
				ret += ')';
				return ret;
			}
		}
	}
	return string(1, arr[y][x]);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j];
		}
	}
	cout << solve(0, 0, N) << '\n';
	return 0;
}