#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	vector<int> home;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		home.push_back(input);
	}

	sort(home.begin(), home.end());

	// 중앙값에 위치한 집에 안테나를 설치
	if (n % 2 == 1) {
		cout << home.at((n / 2 + 1) - 1);
	} 
	else {
		cout << home.at((n / 2) - 1);
	}

	return 0;
}