#include <bits/stdc++.h>

using namespace std;

int s;
int idx = 1;

void main() {
	cin >> s;

	while (s >= idx) {
		s -= idx;
		idx++;
	}
	
	idx -= 1;

	cout << idx;
	
}