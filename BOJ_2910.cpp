#include <bits/stdc++.h>
using namespace std;

int n, c;
int arr[1001];
vector<pair<int, int>> v;
map<int, int> mp, mp2;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return mp2[a.second] < mp2[b.second];
	}
	return a.first > b.first;
}

int main() {
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]]++;
		if (mp2[arr[i]] == 0) mp2[arr[i]] = i + 1;
	}

	for (auto it : mp) {
		v.push_back({ it.second, it.first });
	}
	sort(v.begin(), v.end(), cmp);

	for (auto i : v) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second << " ";
		}
	}
	return 0;
}