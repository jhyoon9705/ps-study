#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> height, diff;
	int answer = 0;
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		height.push_back(input);
	}

	// �̿��� �������� Ű ���̸� ��� ����
	for (int i = 0; i < n - 1; i++) {
		diff.push_back(height.at(i + 1) - height.at(i));
	}

	// Ű ���̸� ������������ ����
	sort(diff.begin(), diff.end());

	// k���� ���� ������ k-1���� Ű ���̴� �ٸ� ���� ������ �Ǳ� ������ ������� �ʾƵ� ��
	for (int i = 0; i < n - k; i++) {
		answer += diff.at(i);
	}
	cout << answer;
	
	return 0;
}