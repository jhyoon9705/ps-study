#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> house;

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		house.push_back(input);
	}
	sort(house.begin(), house.end());

	int start = 1;
	int end = house[n - 1] - house[0];
	int ret = 0;

	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 1;
		int prev_house = house[0];
		for (int i = 1; i < n; i++) {
			if (house[i] - prev_house >= mid) {
				cnt++;
				prev_house = house[i];
			}
		}
		// �����⸦ ���� ���� �̻� ����� ���, �����⸦ ��ġ�ϴ� �Ÿ��� �ø�
		if (cnt >= c) {
			ret = max(ret, mid);
			start = mid + 1;
		}
		// �����⸦ ���� ���� �̸� ����� ���, �����⸦ ��ġ�ϴ� �Ÿ��� ����
		else end = mid - 1;
	}
	cout << ret << "\n";
	return 0;
}