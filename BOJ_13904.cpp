#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}


int main() {
	int N;
	cin >> N;

	int total = 0;
	vector<pair<int, int>> hw;
	int did[1000] = { 0 };

	int time, point;
		
	for (int i = 0; i < N; i++) {
		cin >> time >> point;
		hw.push_back(make_pair(time, point));
	}

	// 과제 배당 점수 순으로 정렬
	sort(hw.begin(), hw.end(), cmp);

	// 배점이 큰 과제부터 채워나가되 그 과제를 최대한 늦게 수행(n일까지면 1~n일 중 할 수 있는 가장 마지막날에)
	for (int i = 0; i < N; i++) {
		int myTime = hw[i].first;
		int myPoint = hw[i].second;

		int pointer = myTime - 1;
		while (pointer >= 0) {
			if (did[pointer] == 0) {
				did[pointer] = myPoint;
				break;
			}
			pointer--;
		}
	}

	for (int j = 0; j < 1000; j++) {
		total += did[j];
	}
	
	cout << total << endl;
}