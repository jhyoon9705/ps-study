#include <bits/stdc++.h>

using namespace std;

int point[21][21];
bool checker[22];
int N;
int answer = 1000000000;

void DFS(int counter, int pos) {
	if (counter == N / 2) {
		int startTeam = 0;
		int linkTeam = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (checker[i] == true && checker[j] == true) startTeam += point[i][j];
				if (checker[i] == false && checker[j] == false) linkTeam += point[i][j];
			}
		}
		answer = min(answer, abs(startTeam - linkTeam));
		return;
	}

	for (int i = pos; i < N; i++) {
		checker[i] = true;
		DFS(counter + 1, i + 1);
		checker[i] = false; // back-tracking
	}
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> point[i][j];
		}
	}
	DFS(0, 1);
	cout << answer;

	return 0;
}