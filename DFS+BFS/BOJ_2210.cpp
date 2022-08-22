#include <bits/stdc++.h>

using namespace std;

int arr[5][5];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> v;

void DFS(int y, int x, int num, int counter) {
	if (counter == 6) {
		v.push_back(num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (newX < 0 || newX >= 5 || newY < 0 || newY >= 5) continue;

		DFS(newY, newX, num * 10 + arr[newY][newX], counter + 1);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			DFS(i, j, 0, 0);
		}
	}

	sort(v.begin(), v.end());
	// unique 함수는 중복되어 밀리게된 원소의 시작부분의 주소를 return
	v.erase(unique(v.begin(), v.end()), v.end());

	cout << v.size();

	return 0;
}