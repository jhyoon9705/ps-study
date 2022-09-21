#include <bits/stdc++.h>

using namespace std;

int N;
int arr[9];
vector<int> v;
int result = 0;
bool visited[9];

void DFS() {
	if (v.size() == N) {
		int temp = 0;
		for (int i = 0; i < N - 1; i++) {
			temp += abs(v[i + 1] - v[i]);
		}
		result = max(result, temp);
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			v.push_back(arr[i]);
			visited[i] = true;
			DFS();
			// back-tracking
			v.pop_back();
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	DFS();
	cout << result;

	return 0;
}