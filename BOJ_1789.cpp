// BOJ_1789 (https://www.acmicpc.net/problem/1789)
#include <bits/stdc++.h>

using namespace std;

long long s;
long long idx = 1;

int main() {
	cin >> s;

	while (s >= idx) {
		s -= idx;
		idx++;
	}
	
	idx -= 1;
	cout << idx;
}