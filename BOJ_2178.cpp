#include <bits/stdc++.h>

using namespace std;
int arr[101][101];
bool visited[101][101] = { 0 }; // 방문 기록
int countArr[101][101] = { 0 }; // 해당 지점까지 올 때 거친 칸 개수
int n, m; // 미로 크기
queue<pair<int, int>> q;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// BFS
void findPath(int row, int col) {
	q.push({ row, col }); // queue에 시작 지점 데이터 삽입
	visited[row][col] = true; // 시작 지점 방문처리
	countArr[row][col] = 1; // 출발지점까지 온 거리를 1로 설정

	while (!q.empty()) {
		int prevRow = q.front().first;
		int prevCol = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) { // 현재 지점에서 상하좌우 지점 확인
			int nRow = prevRow + dx[i];
			int nCol = prevCol + dy[i];

			// 이동 시 미로를 벗어나지 않고, 아직 방문하지 않았으며, 길이 있는지 확인
			if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && visited[nRow][nCol] != true && arr[nRow][nCol] == 1) {
				q.push({ nRow, nCol });
				visited[nRow][nCol] = true; // 방문 처리
				countArr[nRow][nCol] = countArr[prevRow][prevCol] + 1; // 이전 지점에서 한 칸 더 이동했으므로 이전 countArr에서 +1
			}
		}
	}
}

int main() {
		
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}

	findPath(0, 0);

	cout << countArr[n-1][m-1] << endl;

}