#include <bits/stdc++.h>
using namespace std;

int n;
string ret;

bool isPrime(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

void solve(string s) {
	if (s.length() == n) {
		if (isPrime(atoi(s.c_str()))) {
			cout << s << '\n';
			return;
		}
	}
	for (int i = 0; i <= 9; i++) {
		if (isPrime(atoi((s + to_string(i)).c_str()))) solve(s + to_string(i));
	}
}

int main() {
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		if (isPrime(i)) solve(to_string(i));
	}
	return 0;
}