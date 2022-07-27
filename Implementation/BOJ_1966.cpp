#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		
		int counter = 0;
		int n, m;
		cin >> n >> m;

		queue<pair<int, int>> q;
		priority_queue<int> pq;

		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			q.push({ j, input });
			pq.push(input);
		}

		while (!q.empty()) {
			int order = q.front().first;
			int importance = q.front().second;
			q.pop();

			if (pq.top() == importance) { // ���� �켱������ ���� �۾��� �켱������ ���� �տ� �ִ� �۾��� �켱������ ���� ���
				pq.pop(); // ����Ʈ ���(�۾� ����)
				counter++;
				if (order == m) { // ã�� �ִ� �۾��� ���
					cout << counter << '\n';
					break;
				}
			}
			else {
				q.push({ order, importance }); // �ش� �۾��� �� �ڷ� ����
			}
		}
	}

	return 0;
}