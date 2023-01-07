#include <bits/stdc++.h>

using namespace std;

char board[51][51];
int N;

int eat() {
	int temp = 1;

	for (int i = 0; i < N; i++) {
		int count = 1;
		for (int j = 1; j < N; j++) { // 행에서 비교
			if (board[i][j] == board[i][j - 1]) count++; // 같은게 있으면 1씩 카운트
			else count = 1; // 같은게 없으면 1

			temp = max(count, temp);
		}
	}

	for (int j = 0; j < N; j++) {
		int count = 1;
		for (int i = 1; i < N; i++) { // 열에서 비교
			if (board[i][j] == board[i - 1][j]) count++;
			else count = 1;

			temp = max(count, temp);
		}
	}
	return temp;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < N; j++) {
			board[i][j] = input[j];
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j + 1 < N) {
				swap(board[i][j], board[i][j + 1]); // 좌우 교환
				answer = max(answer, eat()); // 먹을 수 있는 사탕을 계산
				swap(board[i][j], board[i][j + 1]); // 원래대로
			}
			if (i + 1 < N) {
				swap(board[i][j], board[i + 1][j]); // 상하 교환
				answer = max(answer, eat()); // 먹을 수 있는 사탕을 계산
				swap(board[i][j], board[i + 1][j]); // 원래대로
			}
		}
	}
	cout << answer;
	return 0;
}