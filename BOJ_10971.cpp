#include <bits/stdc++.h>

using namespace std;

int N;
int arr[11][11];
bool visited[11];
vector<int> v;
int answer = 1000000000;

void func(int start, int index, int count, int sum) {
	if (count == N) {
		if (arr[index][start] == 0) return; // ������ �������� ��� ������ �ǵ��ƿ� �� ���� ���
		if (answer > sum + arr[index][start]) answer = sum + arr[index][start];
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == true || arr[index][i] == 0) continue;
		visited[i] = true;
		func(start, i, count + 1, sum + arr[index][i]);
		visited[i] = false;
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		visited[i] = true;
		func(i, i, 1, 0); // ��� ����, ���� ��ġ. ������ ���� ��, ���
		visited[i] = false;
	}

	cout << answer;

	return 0;

}