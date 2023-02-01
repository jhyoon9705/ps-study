#include <bits/stdc++.h>
using namespace std;

int n;
int strength[101], happy[101], dp[101];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> strength[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> happy[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 100; j > strength[i]; j--) {
			dp[j] = max(dp[j], dp[j - strength[i]] + happy[i]);
		}
	}
	cout << dp[100] << "\n";
	return 0;
}

/* #include <bits/stdc++.h>

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
}*/