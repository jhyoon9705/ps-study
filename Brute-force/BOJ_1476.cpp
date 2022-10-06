#include <bits/stdc++.h>

using namespace std;

int E, S, M;
const int EMAX = 15;
const int SMAX = 28;
const int MMAX = 19;
int answer = 1;
int ee = 1;
int ss = 1;
int mm = 1;

int main() {
	cin >> E >> S >> M;

	while (1) {
		if (E == ee && S == ss && M == mm) break;

		ee++;
		mm++;
		ss++;
		answer++;

		if (ee > EMAX) ee = 1;
		if (ss > SMAX) ss = 1;
		if (mm > MMAX) mm = 1;
	}

	cout << answer;
	return 0;
}