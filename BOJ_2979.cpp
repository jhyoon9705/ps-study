#include <bits/stdc++.h>
using namespace std;

int fee[4];
int pTime[101];
int sum = 0;

int main() {
	cin >> fee[1] >> fee[2] >> fee[3];

	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;
		for (int j = start + 1; j <= end; j++) {
			pTime[j]++;
		}
	}
	for (int i = 0; i < 101; i++) {
		sum += pTime[i] * fee[pTime[i]];
	}
	cout << sum << '\n';
	return 0;
}