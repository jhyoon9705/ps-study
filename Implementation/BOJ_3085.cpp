#include <bits/stdc++.h>

using namespace std;

char board[51][51];
int N;

int eat() {
	int temp = 1;

	for (int i = 0; i < N; i++) {
		int count = 1;
		for (int j = 1; j < N; j++) { // �࿡�� ��
			if (board[i][j] == board[i][j - 1]) count++; // ������ ������ 1�� ī��Ʈ
			else count = 1; // ������ ������ 1

			temp = max(count, temp);
		}
	}

	for (int j = 0; j < N; j++) {
		int count = 1;
		for (int i = 1; i < N; i++) { // ������ ��
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
				swap(board[i][j], board[i][j + 1]); // �¿� ��ȯ
				answer = max(answer, eat()); // ���� �� �ִ� ������ ���
				swap(board[i][j], board[i][j + 1]); // �������
			}
			if (i + 1 < N) {
				swap(board[i][j], board[i + 1][j]); // ���� ��ȯ
				answer = max(answer, eat()); // ���� �� �ִ� ������ ���
				swap(board[i][j], board[i + 1][j]); // �������
			}
		}
	}
	cout << answer;
	return 0;
}