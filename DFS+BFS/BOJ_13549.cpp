#include <bits/stdc++.h>

using namespace std;

int n, k;
bool visited[200001];
queue<pair<int, int>> q;
int answer = 0;

void BFS(int n, int k) {
	if (n == k) return;

	q.push({ n, 0 });
	while (!q.empty()) {
		int prevPos = q.front().first;
		int prevTime = q.front().second;
		q.pop();

		// 가중치가 0인 간선이 있기 때문에 큐의 삽입 순서가 이와 같아야 함
		// *2인 간선의 시간이 0초이므로 큐에 가장 먼저 넣어주어야 함
		if (prevPos * 2 <= 100000 && visited[prevPos * 2] == false) { 
			if (prevPos * 2 == k) {
				answer = prevTime;
				break;
			}
			q.push({ prevPos * 2, prevTime });
			visited[prevPos * 2] = true;
		}
		
		if (prevPos - 1 >= 0 && visited[prevPos - 1] == false) {
			if (prevPos - 1 == k) {
				answer = prevTime + 1;
				break;
			}
			q.push({ prevPos - 1, prevTime + 1 });
			visited[prevPos - 1] = true;
		}

		if (prevPos + 1 <= 100000 && visited[prevPos + 1] == false) {
			if (prevPos + 1 == k) {
				answer = prevTime + 1;
				break;
			}
			q.push({ prevPos + 1, prevTime + 1 });
			visited[prevPos + 1] = true;
		}
	}
}

int main() {
	cin >> n >> k;
	BFS(n, k);
	cout << answer;

	return 0;
}