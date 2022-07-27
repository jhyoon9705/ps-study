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

			if (pq.top() == importance) { // 가장 우선순위가 높은 작업의 우선순위와 가장 앞에 있는 작업의 우선순위가 같은 경우
				pq.pop(); // 프린트 출력(작업 수행)
				counter++;
				if (order == m) { // 찾고 있는 작업인 경우
					cout << counter << '\n';
					break;
				}
			}
			else {
				q.push({ order, importance }); // 해당 작업을 맨 뒤로 보냄
			}
		}
	}

	return 0;
}