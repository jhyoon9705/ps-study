// BOJ_11866 (https://www.acmicpc.net/problem/11866)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	int seq = 0;
	vector<int> v;

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
	}
	
	cout << "<";

	for (int j = 0; j < n; j++) {
		seq = (seq + (k - 1)) % v.size();

		if (j == n - 1) {
			cout << v[seq] << ">";
		}
		else {
			cout << v[seq] << ", ";
		}

		v.erase(v.begin() + seq);
	}
	
}