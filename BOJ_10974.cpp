#include <bits/stdc++.h>

using namespace std;

int N;
bool visited[9];
int arr[9];

void DFS(int num) {
	if (num == N) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			arr[num] = i + 1;
			DFS(num + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N;
	DFS(0);

	return 0;
}