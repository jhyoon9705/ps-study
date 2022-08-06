#include <bits/stdc++.h>

using namespace std;

int f, s, g, u, d;
queue<int> q;
int arr[1000001];
bool visited[1000001];

void BFS() {
	q.push(s);
	arr[s] = 0;
	visited[s] = true;
	if (s == g) {
		cout << 0;
		return;
	}

	while (!q.empty()) {
		int prevFloor = q.front();
		q.pop();

		if (prevFloor + u <= f && visited[prevFloor + u] == false) {
			if (prevFloor + u == g) {
				cout << arr[prevFloor] + 1;
				return;
			}
			visited[prevFloor + u] = true;
			arr[prevFloor + u] = arr[prevFloor] + 1;
			q.push(prevFloor + u);
		}

		if (prevFloor - d >= 1 && visited[prevFloor - d] == false) {
			if (prevFloor - d == g) {
				cout << arr[prevFloor] + 1;
				return;
			}
			visited[prevFloor - d] = true;
			arr[prevFloor - d] = arr[prevFloor] + 1;
			q.push(prevFloor - d);
		}
	}

	if (visited[g] == false) {
		cout << "use the stairs";
		return;
	}
	cout << arr[g];
}

int main() {
	cin >> f >> s >> g >> u >> d;
	BFS();
	return 0;
}