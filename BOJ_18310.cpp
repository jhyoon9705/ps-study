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

	// �߾Ӱ��� ��ġ�� ���� ���׳��� ��ġ
	if (n % 2 == 1) {
		cout << home.at((n / 2 + 1) - 1);
	} 
	else {
		cout << home.at((n / 2) - 1);
	}

	return 0;
}