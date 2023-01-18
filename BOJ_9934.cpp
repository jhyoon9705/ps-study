#include <bits/stdc++.h>
using namespace std;

int k, input;
vector<int> v;
vector<int> arr[11];
int inNum = 1;

void solve(int start, int end, int layer) {
	if (start == end) {
		arr[layer].push_back(v[start]);
		return;
	}
	int center = (start + end) / 2;
	arr[layer].push_back(v[center]);
	solve(start, center - 1, layer + 1);
	solve(center + 1, end, layer + 1);
}

int main() {
	cin >> k;
	int inNum = (int)pow(2, k) - 1;
	for (int i = 0; i < inNum; i++) {
		cin >> input;
		v.push_back(input);
	}
	solve(0, inNum - 1, 0);
	for (int i = 0; i < k; i++) {
		for (int n : arr[i]) {
			cout << n << " ";
		}
		cout << '\n';
	}
	return 0;
}