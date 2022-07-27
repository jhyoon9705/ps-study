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
			if (j == 1) { // 해당 줄에서 맨 왼쪽 숫자인 경우 오른쪽 대각선 위 숫자와 합함
				tri[i][j] = tri[i - 1][j] + tri[i][j];
			}
			else if (i == j) { // 해당 줄에서 가장 오른쪽 숫자인 경우 왼쪽 대각선 위 숫자와 합함
				tri[i][j] = tri[i - 1][j - 1] + tri[i][j];
			}
			else { // 그 외의 경우, 왼쪽 위 대각선의 수의 합과 오른쪽 위 대각선의 수의 합 중 큰 값으로 선택
				tri[i][j] = max(tri[i - 1][j - 1] + tri[i][j], tri[i - 1][j] + tri[i][j]);
			}
		}
	}

	// 가장 아랫줄에 도착하였을 때, 가장 큰 수를 출력
	for (int i = 1; i <= n; i++) {
		if (maxNumber < tri[n][i]) {
			maxNumber = tri[n][i];
		}
	}

	cout << maxNumber;

}