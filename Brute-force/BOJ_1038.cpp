#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> v;

void DFS(long long index, int count) {
	if (count > 10) return;
	
	v.push_back(index);
	for (int i = 0; i < 10; i++) {
		if (index % 10 > i) {
			DFS(index * 10 + i, count + 1);
		}
	}
	return;
}

int main() {
	cin >> N;

	for (int i = 0; i < 10; i++) {
		DFS(i, 1);
	}

	sort(v.begin(), v.end());
	if (v.size() <= N) cout << "-1" << '\n';
	else cout << v[N] << '\n';
	
	return 0;
}