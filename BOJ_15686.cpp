// 각 집에 대하여 m개의 치킨집까지의 치킨거리를 모두 구하여 가장 작은 수를 더해주기
#include <bits/stdc++.h>

using namespace std;

int n, m;
int MIN = 987654321;
vector<pair<int, int>> home, chicken, open;
bool selected[13];

void find_chicken_dist() {
	int result = 0;
	for (int i = 0; i < (int)home.size(); i++) { // 각 집에서
		int min_dist = 987654321;
		for (int j = 0; j < (int)open.size(); j++) { // 선택한 치킨집에 대하여
			min_dist = min(min_dist, abs(home[i].first - open[j].first) + abs(home[i].second - open[j].second)); // 최소 치킨거리 찾기
		}
		result += min_dist; // 도시의 최소 치킨거리
	}
	MIN = min(MIN, result);
}

void find_open_chicken(int x, int counter) {
	if (counter == m) {
		find_chicken_dist(); // m개의 치킨집을 고른 후, 치킨거리가 최소인 치킨집 찾기
	}

	// m개의 치킨집 고르기
	for (int i = x; i < (int)chicken.size(); i++) {
		if (selected[i] == true) continue;

		selected[i] = true;
		open.push_back({ chicken[i].first, chicken[i].second });
		find_open_chicken(i, counter + 1);
		selected[i] = false;
		open.pop_back();
	}
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			if (input == 1) {
				home.push_back({ i, j });
			}
			else if (input == 2) {
				chicken.push_back({ i, j });
			}
		}
	}
	find_open_chicken(0, 0);
	cout << MIN;
	return 0;
}