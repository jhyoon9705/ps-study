#include <bits/stdc++.h>

using namespace std;
int arr[101][101];
bool visited[101][101] = { 0 }; // �湮 ���
int countArr[101][101] = { 0 }; // �ش� �������� �� �� ��ģ ĭ ����
int n, m; // �̷� ũ��
queue<pair<int, int>> q;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// BFS
void findPath(int row, int col) {
	q.push({ row, col }); // queue�� ���� ���� ������ ����
	visited[row][col] = true; // ���� ���� �湮ó��
	countArr[row][col] = 1; // ����������� �� �Ÿ��� 1�� ����

	while (!q.empty()) {
		int prevRow = q.front().first;
		int prevCol = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) { // ���� �������� �����¿� ���� Ȯ��
			int nRow = prevRow + dx[i];
			int nCol = prevCol + dy[i];

			// �̵� �� �̷θ� ����� �ʰ�, ���� �湮���� �ʾ�����, ���� �ִ��� Ȯ��
			if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && visited[nRow][nCol] != true && arr[nRow][nCol] == 1) {
				q.push({ nRow, nCol });
				visited[nRow][nCol] = true; // �湮 ó��
				countArr[nRow][nCol] = countArr[prevRow][prevCol] + 1; // ���� �������� �� ĭ �� �̵������Ƿ� ���� countArr���� +1
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