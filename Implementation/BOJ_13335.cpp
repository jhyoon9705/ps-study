#include <bits/stdc++.h>

using namespace std;

int n, w, L;
int onBridge = 0;
int order = 0;
int answer = 0;
vector<int> truck;
queue<int> q;

int main() {
	cin >> n >> w >> L;
	
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		truck.push_back(input);
	}

	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) { // �ٸ��� �� �� ���
				onBridge -= q.front(); // �� �տ� �ִ� Ʈ���� �ٸ� ������ ������,
				q.pop(); // �ٸ� �� Ʈ�� queue���� ����
			}

			if (onBridge + truck.at(i) <= L) break; // �ٸ� ���� ���� Ʈ���� �ø� �� �ִ� ��쿡�� �ݺ����� ���������� �ٸ� ���� Ʈ�� �ø���

			q.push(0); // �ٸ� ���� ���� Ʈ���� �� �ø��� �� timing�� �׳� ���(���԰� 0�� Ʈ��)
			answer++; // �ð� 1 ����
		}
		q.push(truck.at(i)); // �ٸ� ���� Ʈ�� �ø���
		onBridge += truck.at(i); // �ٸ� ���� Ʈ���� ���� ���
		answer++; // �ð� 1 ����
	}
	cout << answer + w;
	
	return 0;
}