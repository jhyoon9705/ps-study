#include <bits/stdc++.h>

using namespace std;

int N;
int answer = 0;
int arr[15];

bool isValid(int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[n] || abs(arr[n] - arr[i]) == n - i) return false; // 같은 행과 열이거나 대각선인 경우
	}
	return true;
}

void DFS(int num) {
	if (num == N) answer++;
	else {
		for (int i = 0; i < N; i++) {
			arr[num] = i; // 퀸을 배치

			// back-tracking; 유효하면 다음 행에 퀸을 배치, 아니면 다른 위치로 퀸 배치를 변경
			if (isValid(num)) {
				DFS(num + 1);
			}
		}
	}
}

int main() {
	cin >> N;

	DFS(0);
	cout << answer;
	return 0;
}