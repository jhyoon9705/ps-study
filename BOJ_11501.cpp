// �ڿ������� �ְ��� �ְ��� �����س����� �ִ� ������ ���
// �ְ��� �ٲ��� ������ �ż�
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		vector<int> v;
		long long profit = 0;
		long long tempMax = 0;
		int N;
		cin >> N;

		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			v.push_back(input);
		}
		
		tempMax = v[N - 1];
		for (int j = N - 2; j >= 0; j--) {
			if (v[j] < tempMax) {
				profit += (tempMax - v[j]);
			}
			else {
				tempMax = v[j];
			}
		}
		cout << profit << "\n";
	}
	return 0;
}