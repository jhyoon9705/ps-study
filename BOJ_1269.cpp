#include <bits/stdc++.h>
using namespace std;

int aNum, bNum, input, ret;
map<int, int> mp;

int main() {
	cin >> aNum >> bNum;
	for (int i = 0; i < aNum; i++) {
		cin >> input;
		mp[input]++;
	}
	for (int i = 0; i < bNum; i++) {
		cin >> input;
		mp[input]++;
	}
	for (auto i : mp) {
		if (i.second == 1) ret++;
	}
	cout << ret << '\n';
	return 0;
}