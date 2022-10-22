#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> strength, pleasure;

int answer = 0;

void func(int s, int p, int order) {
	if (s <= 0) return;
	if (order >= N) {
		answer = max(answer, p);
		return;
	}

	answer = max(answer, p);

	func(s - strength[order], p + pleasure[order], order + 1);
	func(s, p, order + 1);
}

int main() {
	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		strength.push_back(input);
	}
	for (int i = 0; i < N; i++) {
		cin >> input;
		pleasure.push_back(input);
	}

	func(100, 0, 0);

	cout << answer;
	return 0;
}