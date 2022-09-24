#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, int>> v;
int N, C, M;
int arr[2001];
int answer = 0;

// 1. 도착지 number가 작은 것부터, 2. 출발지 number가 큰 것부터
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
		// 출발지에서 도착지까지 가는 중에 싣고 가는 가장 많은 박스의 수
		for (int j = from; j < to; j++) {
			maxNum = max(maxNum, arr[j]);
		}

		int canLoad = C - maxNum; // 싣을 수 있는 최대 박스 수
			
		// 싣을 수 있는 박스의 수가 싣어야 할 박스보다 많은 경우
		if (canLoad >= box) {
			for (int j = from; j < to; j++) {
				arr[j] += box;
			}			
			answer += box;
		}

		// 싣을 수 있는 박스의 수가 싣어야 할 박스보다 적은 경우
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