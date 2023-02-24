#include <bits/stdc++.h>
using namespace std;

string input;
map<string, int> availCase;
struct A {
	int _a, _b, _c;
};
A order[8] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7} , {2, 5, 8}, {0, 4, 8}, {2, 4, 6} };

bool bingo(string s, char c) {
	for (int i = 0; i < 8; i++) {
		if (s[order[i]._a] == c && s[order[i]._b] == c && s[order[i]._c] == c) return true;
	}
	return false;
}

bool check(string s, int x, int o) {
	if (x + o == 9) return true;
	if (bingo(s, 'X') || bingo(s, 'O')) return true;
	return false;
}

void findAvailCase(string s, int x, int o) {
	if (check(s, x, o)) {
		availCase[s] = 1;
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (s[i] == '.') {
			if (x == o) {
				s[i] = 'X';
				findAvailCase(s, x + 1, o);
				s[i] = '.';
			}
			else {
				s[i] = 'O';
				findAvailCase(s, x, o + 1);
				s[i] = '.';
			}
		}
	}
}

int main() {
	findAvailCase(".........", 0, 0);
	while (true) {
		cin >> input;
		if (input == "end") break;
		if (availCase.find(input) != availCase.end()) cout << "valid" << "\n";
		else cout << "invalid" << "\n";
	}
	return 0;
}