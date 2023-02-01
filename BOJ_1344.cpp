#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

double a, b, dp[20][20][20];
const int game = 18;
bool isPrime[20];

double solve(int idx, int x, int y) {
	if (idx == game) return isPrime[x] || isPrime[y] ? 1.0 : 0.0;
	double& ret = dp[idx][x][y];
	if (ret > -0.5) return ret;
	ret = 0.0;
	ret += solve(idx + 1, x + 1, y) * a * (1 - b);
	ret += solve(idx + 1, x + 1, y + 1) * a * b;
	ret += solve(idx + 1, x, y + 1) * (1 - a) * b;
	ret += solve(idx + 1, x, y) * (1 - a) * (1 - b);
	return ret;
}

void eratos() {
	fill(isPrime, isPrime + 20, 1);
	isPrime[0] = 0;
	isPrime[1] = 0;
	for (int i = 2; i < 20; i++) {
		for (int j = 2 * i; j < 20; j += i) {
			isPrime[j] = 0;
		}
	}
}

int main() {
	scanf("%lf %lf", &a, &b);
	a /= 100;
	b /= 100;
	eratos();
	memset(dp, -1, sizeof(dp));
	printf("%.6lf", solve(0, 0, 0));
}