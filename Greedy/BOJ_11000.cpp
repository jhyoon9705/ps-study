#include <bits/stdc++.h>

using namespace std;

// �ð�ǥ ���
vector<pair<int, int>> timetable;

// ���� �ð� priority queue
priority_queue<int, vector<int>, greater<int>> pq;

int greedy(int N) {
	pq.push(timetable[0].second); // ���۽ð��� ���� ���� ������ ����ð��� pq�� push

	for (int i = 1; i < N; i++) {
		pq.push(timetable[i].second); // i��° ������ ����ð��� pq�� insert

		// pq�� �ִ� ���� ���� ����ð����� i��° ������ �ʰ� �����ϸ� �� ���ǽ� ����� �����ϹǷ� ���� ���� ����ð� pop
		if (pq.top() <= timetable[i].first) { 
			pq.pop();
		}
	}

	return pq.size();
}



int main() {
	int N;
	cin >> N;

	int start, end;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		timetable.push_back(make_pair(start, end));
	}

	sort(timetable.begin(), timetable.end());

	cout << greedy(N) << endl;
}