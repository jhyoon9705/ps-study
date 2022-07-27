#include <bits/stdc++.h>

using namespace std;

// 시간표 목록
vector<pair<int, int>> timetable;

// 종료 시간 priority queue
priority_queue<int, vector<int>, greater<int>> pq;

int greedy(int N) {
	pq.push(timetable[0].second); // 시작시간이 가장 빠른 수업의 종료시간을 pq에 push

	for (int i = 1; i < N; i++) {
		pq.push(timetable[i].second); // i번째 수업의 종료시간을 pq에 insert

		// pq에 있는 가장 빠른 종료시간보다 i번째 수업이 늦게 시작하면 한 강의실 사용이 가능하므로 가장 빠른 종료시간 pop
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