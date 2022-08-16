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

		while (i + 1 < n - 1 && currentPrice <= oil.at(i + 1)) { // ���� �����Һ��� ���� �����Ұ� ������ �� ���, ���� �����Ҹ� ��ġ�� ����
			i++;
			currentDistance += road.at(i);
		}
		totalPrice += (currentDistance * currentPrice); // �⸧�� �߰� ���
	}

	cout << totalPrice;

	return 0;
}