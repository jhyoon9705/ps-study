#include <bits/stdc++.h>

using namespace std;

char graph[19][19];
int moving[4][2] = { {0,1},{1,0},{1,1},{-1,1} };
bool visited[19][19][4][2];

char dfs(int row, int col, int dir, char color, int cnt) {
	visited[row][col][dir][color - '1'] = true;
	int newRow = row + moving[dir][0];
	int newCol = col + moving[dir][1];
	if (newRow < 0 || newRow >= 19 || newCol < 0 || newCol >= 19 || graph[newRow][newCol] != color) {
		if (cnt == 5) {
			return color;
		}
		else {
			return '0';
		}
	}
	return dfs(newRow, newCol, dir, color, cnt + 1);

}

int main() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (graph[j][i] != '0') {
				for (int dir = 0; dir < 4; dir++) {
					if (visited[j][i][dir][graph[j][i] - '1'])continue;
					if (dfs(j, i, dir, graph[j][i], 1) != '0') {
						cout << graph[j][i] << '\n' << j + 1 << ' ' << i + 1;
						return 0;
					}
				}
			}
		}
	}

	cout << 0;
	return 0;
}