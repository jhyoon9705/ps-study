#include <bits/stdc++.h>
using namespace std;

int n, m, j, input;
int ret = 0;
queue<int> q;

int solve() {
	int left = 1;
	int right = left + m - 1;
	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		if (left <= pos && pos <= right) continue;
		else if (pos < left) {
			while (left != pos) {
				left--;
				right--;
				ret++;
			}
		}
		else if (pos > right) {
			while (right != pos) {
				left++;
				right++;
				ret++;
			}
		}
	}
	return ret;
}

int main() {
	cin >> n >> m;
	cin >> j;
	for (int i = 0; i < j; i++) {
		cin >> input;
		q.push(input);
	}
	cout << solve() << '\n';
	return 0;
}