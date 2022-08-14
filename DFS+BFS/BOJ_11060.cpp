#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000];
bool visited[1000];
int counter[1000];
queue<pair<int, int>> q;

void BFS() {
	counter[0] = 0;
	q.push({0, arr[0]});
	visited[0] = true;

	while (!q.empty()) {
		int prevPos = q.front().first;
		int prevNum = q.front().second;		
		q.pop();

		for (int i = 1; i <= prevNum; i++) {
			if ((prevPos + i < n) && (arr[prevPos + i] != 0) && (visited[prevPos + i] == false)) {
				q.push({ prevPos + i, arr[prevPos + i]});
				visited[prevPos + i] = true;
				counter[prevPos + i] = counter[prevPos] + 1;
				if (prevPos + i == n - 1) return;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	BFS();

	if (n != 1 && counter[n - 1] == 0) cout << -1; // n!= 1인 경우: 시작점이 도착점인 경우
	else cout << counter[n - 1];

	return 0;
}