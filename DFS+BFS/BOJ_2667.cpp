#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 25;
int houseMap[MAXSIZE][MAXSIZE] = { -1 };
bool visited[MAXSIZE][MAXSIZE] = { 0 };
int mapSize, counter = 0;
queue<pair<int, int>> q;
vector<int> result;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void BFS(int x, int y) {
	q.push({ x, y });
	visited[x][y] = true;
	counter++;
	
	while (!q.empty()) {
		int coX = q.front().first;
		int coY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nCoX = coX + dx[i];
			int nCoY = coY + dy[i];
			if (0 <= nCoX && 0 <= nCoY && nCoX < mapSize && nCoY < mapSize && visited[nCoX][nCoY] == false && houseMap[nCoX][nCoY] == 1) {
				q.push({ nCoX, nCoY });
				visited[nCoX][nCoY] = true;
				counter++;
			}

		}
	}
}

int main() {
	cin >> mapSize;

	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			scanf_s("%1d", &houseMap[i][j]); // insert number one by one to the array
		}
	}

	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			if (houseMap[i][j] == 1 && visited[i][j] == false) {
				counter = 0;
				BFS(i, j);
				result.push_back(counter);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << endl;

	for (int i = 0; i < (int)result.size(); i++) {
		cout << result[i] << endl;
	}

}