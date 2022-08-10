#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int arrA[50][50];
int arrB[50][50];
int counter = 0;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arrA[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arrB[i][j]);
		}
	}

	// A����� 1�� 1�� ���Һ��� B��İ� ���ذ��� �ٸ� ��� 3*3����� 0-1 ��ȯ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (arrA[i][j] != arrB[i][j]) { // �� ����� ���Ұ� �ٸ� ��� 0-1 ��ȯ
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						arrA[i + k][j + l] = !arrA[i + k][j + l];
					}
				}
				counter++;
			}
		}
	}

	// ��� ������������ �ٸ� ���Ұ� ���� ���, -1 ��� (��ȯ �Ұ�)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arrA[i][j] != arrB[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << counter;
	return 0;
}