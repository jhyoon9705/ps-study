#include <bits/stdc++.h>

using namespace std;

int N, S;
vector<int> v;
int counter = 0;
bool visited[21];

void DFS(int index, int temp) {
	if (index == N) return;
	if (temp + v[index] == S) counter++;

	DFS(index + 1, temp); // ���� Ž���� �ϸ鼭, Ž���� ���� ������ �ʰų�
	DFS(index + 1, temp + v[index]); // Ž���� ���� ���ϰų�
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	DFS(0, 0);
	cout << counter;

	return 0;
}