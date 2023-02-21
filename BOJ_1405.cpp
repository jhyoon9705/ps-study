#include <bits/stdc++.h>
using namespace std;

int visited[30][30];
double percent[4];
int n;
double ret;
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

void move(int row, int col, int num, double temp) {
	if (num == n) {
		ret += temp;
		return;
	}
	visited[row][col] = 1;
	for (int i = 0; i < 4; i++) {
		int nRow = row + dy[i];
		int nCol = col + dx[i];
		if (visited[nRow][nCol]) continue;
		move(nRow, nCol, num + 1, temp * (percent[i] / 100));
		visited[nRow][nCol] = 0;
	}
}

int main() {
	cin >> n >> percent[0] >> percent[1] >> percent[2] >> percent[3];
	move(15, 15, 0, 1.0);
	cout.precision(10);
	cout << ret << '\n';
	return 0;
}