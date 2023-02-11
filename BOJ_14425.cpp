#include <bits/stdc++.h>
using namespace std;

map<string, int> a, b;
string s;
int n, m, ret;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		a[s] = 1;
	}
	for (int j = 0; j < m; j++) {
		cin >> s;
		if (a[s]) ret++;
	}
	cout << ret << "\n";
	return 0;
}