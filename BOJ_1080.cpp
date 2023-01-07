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

	// A행렬의 1행 1열 원소부터 B행렬과 비교해가며 다른 경우 3*3행렬을 0-1 변환
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (arrA[i][j] != arrB[i][j]) { // 두 행렬의 원소가 다른 경우 0-1 변환
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						arrA[i + k][j + l] = !arrA[i + k][j + l];
					}
				}
				counter++;
			}
		}
	}

	// 모두 변경했음에도 다른 원소가 있을 경우, -1 출력 (변환 불가)
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