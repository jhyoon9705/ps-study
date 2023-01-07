#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> sensor, dist;
int answer = 0;

int main() {
	cin >> n;
	cin >> k;

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		sensor.push_back(input);
	}
	// ������ ��ġ�� ������������ ����
	sort(sensor.begin(), sensor.end());

	// �̿��� ���� ���� �Ÿ��� ���ϱ�
	for (int i = 0; i < n - 1; i++) {
		dist.push_back(abs(sensor.at(i) - sensor.at(i + 1)));
	}
	// �̿��� ���� ���� �Ÿ����� ������������ ����
	sort(dist.begin(), dist.end());

	// ���� ������ �Ÿ��� ���� ���� ���� �ٸ� ���߱��� ����ϵ��� ��
	// ����, �̿��� ���� ���� �Ÿ����� �߿� (���߱��� �� - 1)���� ū ������ ������ �������� ��� �ջ�
	for (int i = 0; i < (int)dist.size() - (k - 1); i++) {
		answer += dist.at(i);
	}

	cout << answer;

	return 0;
}