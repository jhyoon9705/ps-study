#include <bits/stdc++.h>
using namespace std;

int n, ret, answer;
int dice[10001][6];

int opposite(int num) {
	if (num == 0) return 5;
	else if (num == 1) return 3;
	else if (num == 2) return 4;
	else if (num == 3) return 1;
	else if (num == 4) return 2;
	else return 0;
}

int findMax(int a, int b) {
	if (a == 6 || b == 6) {
		if (a == 5 || b == 5) return 4;
		else return 5;
	}
	else return 6;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> dice[i][j];
		}
	}
	for (int i = 0; i < 6; i++) {
		ret = 0;
		int up = dice[0][i];
		ret += findMax(up, dice[0][opposite(i)]);
		for (int j = 1; j < n; j++) {
			for (int k = 0; k < 6; k++) {
				if (up == dice[j][k]) {
					up = dice[j][opposite(k)];
					ret += findMax(up, dice[j][k]);
					break;
				}
			}
		}
		answer = max(answer, ret);
	}
	cout << answer << "\n";
	return 0;
}