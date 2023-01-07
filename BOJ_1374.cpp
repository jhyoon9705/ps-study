#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> lecture;
	int num, start, end;

	for (int i = 0; i < N; i++) {
		cin >> num >> start >> end;
		lecture.push_back(make_pair(start, end));
	}

	// 강의들을 시작시간 순으로 정렬
	sort(lecture.begin(), lecture.end());

	priority_queue<int, vector<int>, greater<int>> pq;

	// priority queue에서 가장 작은 값(가장 빠른 종료 시각)과 다음 강의 시작시간을 비교
	// 다음 강의 시작시각이 가장 빠른 종료 시각보다 느리면 priority queue에서 pop하고 해당 강의 종료 시각을 push
	// 그렇지 않은 경우, 해당 강의 종료 시각을 push
	for (int i = 0; i < N; i++) {
		if (pq.empty()) {
			pq.push(lecture[i].second);
		}
		else {
			if (pq.top() <= lecture[i].first) {
				pq.pop();
				pq.push(lecture[i].second);
			}
			else {
				pq.push(lecture[i].second);
			}
		}
	}

	cout << (int)pq.size() << endl;
}