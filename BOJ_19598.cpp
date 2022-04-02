#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> meetings;
	priority_queue<int, vector<int>, greater<int>> pq;

	int start, end;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		meetings.push_back(make_pair(start, end));
	}

	sort(meetings.begin(), meetings.end());

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			pq.push(meetings[i].second);
		}
		else {
			if (meetings[i].first >= pq.top()) {
				pq.pop();
				pq.push(meetings[i].second);
			}
			else {
				pq.push(meetings[i].second);
			}
		}
	}

	cout << (int)pq.size() << endl;
}