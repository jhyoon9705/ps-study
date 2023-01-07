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

	// ���ǵ��� ���۽ð� ������ ����
	sort(lecture.begin(), lecture.end());

	priority_queue<int, vector<int>, greater<int>> pq;

	// priority queue���� ���� ���� ��(���� ���� ���� �ð�)�� ���� ���� ���۽ð��� ��
	// ���� ���� ���۽ð��� ���� ���� ���� �ð����� ������ priority queue���� pop�ϰ� �ش� ���� ���� �ð��� push
	// �׷��� ���� ���, �ش� ���� ���� �ð��� push
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