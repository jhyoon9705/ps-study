#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	vector<int> road;
	vector<long long> oil;
	long long totalPrice = 0;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int input;
		cin >> input;
		road.push_back(input);
	}
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		oil.push_back(input);
	}

	for (int i = 0; i < n - 1; i++) {
		long long currentPrice = oil.at(i);
		int currentDistance = road.at(i);

		while (i + 1 < n - 1 && currentPrice <= oil.at(i + 1)) { // 현재 주유소보다 다음 주유소가 가격이 쌀 경우, 다음 주유소를 거치지 않음
			i++;
			currentDistance += road.at(i);
		}
		totalPrice += (currentDistance * currentPrice); // 기름값 중간 계산
	}

	cout << totalPrice;

	return 0;
}