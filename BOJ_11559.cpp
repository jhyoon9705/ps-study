#include <bits/stdc++.h>
using namespace std;

string s;
char arr[12][6];
int visited[12][6], ret;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> v;

void solve(int row, int col, char c) {
	v.push_back({ row, col });
	visited[row][col] = 1;
	for (int k = 0; k < 4; k++) {
		int nRow = row + dy[k];
		int nCol = col + dx[k];
		if (nRow < 0 || nCol < 0 || nRow >= 12 || nCol >= 6 || visited[nRow][nCol]) continue;
		if (arr[nRow][nCol] == c) {
			solve(nRow, nCol, c);
		}
	}
}

void arrange() {
	for (int i = 0; i < 6; i++) {
		int p = 11;
		while (p >= 0) {			
			if (arr[p][i] == '*') {
				for (int k = p; k >= 1; k--) {
					arr[k][i] = arr[k - 1][i];					
				}
				arr[0][i] = '.';
			}
			else p--;
		}
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		cin >> s;
		for (int j = 0; j < 6; j++) {
			arr[i][j] = s[j];
		}
	}

	bool bomb = true;
	while (bomb) {
		memset(visited, 0, sizeof(visited));
		bomb = false;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] != '.' && !visited[i][j]) {
					v.clear();
					solve(i, j, arr[i][j]);
					if (v.size() >= 4) {
						for (auto a : v) {
							arr[a.first][a.second] = '*';
						}
						bomb = true;
					}
				}
			}
		}
		if (bomb) {
			ret++;
			arrange();
		}
	}	
	cout << ret << "\n";
	return 0;
}