#include <bits/stdc++.h>

using namespace std;

int N, S;
vector<int> v;
int counter = 0;
bool visited[21];

void DFS(int index, int temp) {
	if (index == N) return;
	if (temp + v[index] == S) counter++;

	DFS(index + 1, temp); // 완전 탐색을 하면서, 탐색한 수는 더하지 않거나
	DFS(index + 1, temp + v[index]); // 탐색한 수는 더하거나
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