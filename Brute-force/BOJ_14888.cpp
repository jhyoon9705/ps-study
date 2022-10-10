#include <bits/stdc++.h>

using namespace std;

int N;
int numbers[11];
int operators[4];
int maxNum = -1000000001;
int minNum = +1000000001;

void func(int result, int index) {
	if (index == N) {
		if (result > maxNum) maxNum = result;
		if (result < minNum) minNum = result;

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i] > 0) {
			operators[i]--;
			if (i == 0) {
				func(result + numbers[index], index + 1);
			}
			else if (i == 1) {
				func(result - numbers[index], index + 1);
			}
			else if (i == 2) {
				func(result * numbers[index], index + 1);
			}
			else {
				func(result / numbers[index], index + 1);
			}
			operators[i]++;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	func(numbers[0], 1);
	cout << maxNum << '\n';
	cout << minNum;
	return 0;

}