#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> q;
bool visited[100001] = { false, };
int answer = 0;

void BFS(int n, int k) {
	if (n == k) return; // ó������ ���� ��ġ�� �ִ� ��� ����� �ʿ� ����(��: 0)

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
		
		if (prev + 1 <= 100000 && visited[prev + 1] == false) { // visited check ������ ���� üũ ���� ���־�� outOfBound ������ ���� ����
			if (prev + 1 == k) {
				answer = nextCnt;
				break;
			}
			q.push({ prev + 1, nextCnt });
			visited[prev + 1] = true;
		}
		
		if (prev * 2 <= 100000 && visited[prev * 2] == false) { // visited check ������ ���� üũ ���� ���־�� outOfBound ������ ���� ����
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