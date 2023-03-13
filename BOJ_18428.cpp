#include <bits/stdc++.h>
using namespace std;

int n;
char arr[7][7];
vector<pair<int, int>> teacher;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
bool notDetected = true;

void solve() {
	for (auto t : teacher) {
		int row = t.first;
		int col = t.second;
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			int pRow = row;
			int pCol = col;
			while(!flag) {
				int nRow = pRow + dy[i];
				int nCol = pCol + dx[i];
				if (nRow < 0 || nCol < 0 || nRow >= n || nCol >= n) break;
				if (arr[nRow][nCol] == 'S') {
					flag = true;
					return;
				}
				if (arr[nRow][nCol] == 'O') break;
				pRow = nRow;
				pCol = nCol;
			}
		}
	}
	cout << "YES" << "\n";
	exit(0);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'T') teacher.push_back({ i, j });
		}
	}
	for (int i = 0; i < n * n; i++) {
		if (arr[i / n][i % n] != 'X') continue;
		for (int j = i + 1; j < n * n; j++) {
			if (arr[j / n][j % n] != 'X') continue;
			for (int k = j + 1; k < n * n; k++) {
				if (arr[k / n][k % n] != 'X') continue;
				arr[i / n][i % n] = 'O';
				arr[j / n][j % n] = 'O';
				arr[k / n][k % n] = 'O';
				solve();
				arr[i / n][i % n] = 'X';
				arr[j / n][j % n] = 'X';
				arr[k / n][k % n] = 'X';
			}
		}
	}
	cout << "NO" << "\n";
	return 0;
}