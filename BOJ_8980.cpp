#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, int>> v;
int N, C, M;
int arr[2001];
int answer = 0;

// 1. ������ number�� ���� �ͺ���, 2. ����� number�� ū �ͺ���
bool cmp(pair<pair<int, int>, int> v1, pair<pair<int, int>, int> v2) {
	if (v1.first.second == v2.first.second) return v1.first.first > v2.first.first;
	else return v1.first.second < v2.first.second;
}


int main() {
	cin >> N >> C;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int from, to, num;
		cin >> from >> to >> num;
		v.push_back({ { from, to }, num });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < M; i++) {
		int from = v[i].first.first;
		int to = v[i].first.second;
		int box = v[i].second;

		int maxNum = 0;
		// ��������� ���������� ���� �߿� �ư� ���� ���� ���� �ڽ��� ��
		for (int j = from; j < to; j++) {
			maxNum = max(maxNum, arr[j]);
		}

		int canLoad = C - maxNum; // ���� �� �ִ� �ִ� �ڽ� ��
			
		// ���� �� �ִ� �ڽ��� ���� �ƾ�� �� �ڽ����� ���� ���
		if (canLoad >= box) {
			for (int j = from; j < to; j++) {
				arr[j] += box;
			}			
			answer += box;
		}

		// ���� �� �ִ� �ڽ��� ���� �ƾ�� �� �ڽ����� ���� ���
		else {
			for (int j = from; j < to; j++) {
				arr[j] += canLoad;
			}
			answer += canLoad;
		}
	}

	cout << answer;

	return 0;
}