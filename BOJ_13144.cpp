#include <bits/stdc++.h>
using namespace std;

long long input, s, e;
long long ret, n;
vector<int> v;
long long a[100001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}
	while (e < n) {
		if (!a[v[e]]) {
			a[v[e]]++;
			e++;
		}
		else {
			ret += (e - s);
			a[v[s]]--;
			s++;
		}
	}
	ret += (long long)(e - s) * (e - s + 1) / 2;

	cout << ret << '\n';
	return 0;
}