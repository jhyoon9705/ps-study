#include <bits/stdc++.h>
using namespace std;
int arr[101], visited[101], ret[101], n;
int ret_idx = 0;

void solve(int idx, int start) {
	if (visited[idx]) {
		if (idx == start) {
			ret[ret_idx] = start;
			ret_idx++;
		}
	}
	else {
		visited[idx] = 1;
		solve(arr[idx], start);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		solve(i, i);
	}
	cout << ret_idx << '\n';
	for (int i = 0; i < ret_idx; i++) {
		cout << ret[i] << '\n';
	}
	return 0;
}
