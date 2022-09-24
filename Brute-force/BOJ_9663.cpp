#include <bits/stdc++.h>

using namespace std;

int N;
int answer = 0;
int arr[15];

bool isValid(int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[n] || abs(arr[n] - arr[i]) == n - i) return false; // ���� ��� ���̰ų� �밢���� ���
	}
	return true;
}

void DFS(int num) {
	if (num == N) answer++;
	else {
		for (int i = 0; i < N; i++) {
			arr[num] = i; // ���� ��ġ

			// back-tracking; ��ȿ�ϸ� ���� �࿡ ���� ��ġ, �ƴϸ� �ٸ� ��ġ�� �� ��ġ�� ����
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