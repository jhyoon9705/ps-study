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

		// ����ġ�� 0�� ������ �ֱ� ������ ť�� ���� ������ �̿� ���ƾ� ��
		// *2�� ������ �ð��� 0���̹Ƿ� ť�� ���� ���� �־��־�� ��
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