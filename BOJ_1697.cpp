#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> q;
bool visited[100001] = { false, };
int answer = 0;

void BFS(int n, int k) {
	if (n == k) return; // 처음부터 같은 위치에 있는 경우 계산할 필요 없음(답: 0)

	q.push({n , 0});

	while (!q.empty()) {
		int prev = q.front().first;
		int prevCnt = q.front().second;
		q.pop();
		int nextCnt = prevCnt + 1;

		if (prev - 1 >= 0 && visited[prev - 1] == false) {
			if (prev - 1 == k) {
				answer = nextCnt;
				break;
			}
			q.push({ prev - 1, nextCnt });
			visited[prev - 1] = true;
		}
		
		if (prev + 1 <= 100000 && visited[prev + 1] == false) { // visited check 이전에 범위 체크 먼저 해주어야 outOfBound 에러가 나지 않음
			if (prev + 1 == k) {
				answer = nextCnt;
				break;
			}
			q.push({ prev + 1, nextCnt });
			visited[prev + 1] = true;
		}
		
		if (prev * 2 <= 100000 && visited[prev * 2] == false) { // visited check 이전에 범위 체크 먼저 해주어야 outOfBound 에러가 나지 않음
			if (prev * 2 == k) {
				answer = nextCnt;
				break;
			}
			q.push({ prev * 2, nextCnt });
			visited[prev * 2] = true;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	BFS(n, k);

	cout << answer << endl;
	return 0;
}