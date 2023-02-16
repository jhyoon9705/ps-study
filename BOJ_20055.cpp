#include <bits/stdc++.h>
using namespace std;

int input, n, k, isZero, ret;
struct A {
	int power, robot;
};
A belt[202];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> input;
		belt[i] = { input, 0 };
	}

	while (isZero < k) {
		ret++;
		A temp = belt[2 * n];
		for (int i = 2 * n; i >= 2; i--) {
			belt[i] = belt[i - 1];
		}
		belt[1] = temp;
		belt[n].robot = 0;

		for (int i = n - 1; i >= 1; i--) {
			if (belt[i].robot == 1 && belt[i + 1].power > 0 && belt[i + 1].robot == 0) {
				belt[i + 1].robot = 1;
				belt[i + 1].power--;
				if (belt[i + 1].power == 0) isZero++;
				belt[i].robot = 0;
			}
		}
		belt[n].robot = 0;

		if (belt[1].power > 0) {
			belt[1].power--;
			belt[1].robot = 1;
			if (belt[1].power == 0) isZero++;
		}
	}
	cout << ret << "\n";
	return 0;
}