#include <bits/stdc++.h>
using namespace std;

int x;

int main() {
	cin >> x;
	// cout << __popcnt(x) << "\n"; // visual C++
	cout << __builtin_popcount(x) << "\n"; // g++
	return 0;
}