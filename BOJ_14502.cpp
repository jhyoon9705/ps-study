#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[8][8], temp[8][8], virus[8][8];
queue<pair<int, int>> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int answer = 0;

// 배열 복사
void arrCopy(int(*a)[8], int(*b)[8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void BFS() {
	arrCopy(virus, temp);

	// 벽이 3개 세워진 채로 바이러스 퍼뜨리기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus[i][j] == 2) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];

			if (0 <= newX && newX < n && 0 <= newY && newY < m) {
				if (virus[newX][newY] == 0) {
					virus[newX][newY] = 2;
					q.push({ newX, newY });
				}
			}
		}
	}

	int counter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus[i][j] == 0) {
				counter++;
			}
		}
	}
	answer = max(answer, counter);

}

void makeWall(int num) {
	if (num == 3) { // 벽을 3개 세웠으면 BFS 탐색 후 벽 세우기 종료
		BFS();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				temp[i][j] = 1;
				// 재귀호출
				makeWall(num + 1);
				// 재귀호출된 함수가 끝난 후, 원래대로 되돌리기
				temp[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	// 0인 부분에 벽 세우기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arrCopy(temp, arr);
				temp[i][j] = 1;
				makeWall(1);
				temp[i][j] = 0;
			}
		}
	}

	cout << answer;
	return 0;
}