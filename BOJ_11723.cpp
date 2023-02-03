#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int M, n, setNum;
char s[12];

void solve(string command, int num) {
	if (command == "add") {
		setNum |= (1 << num);
	}
	else if (command == "remove") {
		setNum &= ~(1 << num);
	}
	else if (command == "check") {
		if (setNum & (1 << num)) cout << '1' << "\n";
		else cout << '0' << "\n";
	}
	else if (command == "toggle") {
		setNum ^= (1 << num);
	}
	else if (command == "all") {
		setNum = (1 << 21) - 1;
	}
	else {
		setNum = 0;
	}
}

int main() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%s %d", &s, &n);
		solve(s, n);
	}
	return 0;
}