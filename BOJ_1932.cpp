#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int tri[502][502] = { 0, };
	int n;
	int maxNumber = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	maxNumber = tri[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i+1; j++) {
			if (j == 1) { // �ش� �ٿ��� �� ���� ������ ��� ������ �밢�� �� ���ڿ� ����
				tri[i][j] = tri[i - 1][j] + tri[i][j];
			}
			else if (i == j) { // �ش� �ٿ��� ���� ������ ������ ��� ���� �밢�� �� ���ڿ� ����
				tri[i][j] = tri[i - 1][j - 1] + tri[i][j];
			}
			else { // �� ���� ���, ���� �� �밢���� ���� �հ� ������ �� �밢���� ���� �� �� ū ������ ����
				tri[i][j] = max(tri[i - 1][j - 1] + tri[i][j], tri[i - 1][j] + tri[i][j]);
			}
		}
	}

	// ���� �Ʒ��ٿ� �����Ͽ��� ��, ���� ū ���� ���
	for (int i = 1; i <= n; i++) {
		if (maxNumber < tri[n][i]) {
			maxNumber = tri[n][i];
		}
	}

	cout << maxNumber;

}