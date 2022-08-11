#include <bits/stdc++.h>

using namespace std;

int t;
queue<string> q;
int answer = 0;
string password, newPassword;
string digit = "0123456789";
bool flag = false;
map<string, int> visited;

bool isPrime(string s) {
	int num = stoi(s);
	for (int j = 2; j <= sqrt(num); j++) {
		if (num % j == 0) {
			return false;
		}
	}
	return true;
}

void BFS() {
	q.push(password);
	visited[password] = 1;

	while(!q.empty()) {
		string prevPassword = q.front();
		q.pop();

		if (prevPassword == newPassword) { // ��ǥ ��й�ȣ���� �����ϸ� ����
			flag = true;
			return;
		}

		for (int j = 0; j < 4; j++) {
			string tempPassword = prevPassword;
			if (j == 0) {
				for (int k = 1; k <= 9; k++) { // �� ���ڸ��� 0�̸� ���ڸ����� �ƴ�
					tempPassword[j] = digit[k];
					if (visited[tempPassword] == 0 && isPrime(tempPassword) == 1) {
						visited[tempPassword] = visited[prevPassword] + 1;
						q.push(tempPassword);
					}
				}
			}
			else {
				for (int k = 0; k <= 9; k++) {
					tempPassword[j] = digit[k];
					if (visited[tempPassword] == 0 && isPrime(tempPassword) == 1) {
						visited[tempPassword] = visited[prevPassword] + 1;
						q.push(tempPassword);
					}
				}
			}
			
		}
	}
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		while (!q.empty()) q.pop();
		visited.clear();
		flag = false;
		cin >> password >> newPassword;
		
		BFS();

		if (flag == false) { // ���ϴ� ��й�ȣ�� ������ ���� ���
			cout << "Impossible" << '\n';
		}
		else {
			cout << visited[newPassword] - 1 << '\n';
		}
		
	}

	return 0;
}