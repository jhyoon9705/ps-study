#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> sensor, dist;
int answer = 0;

int main() {
	cin >> n;
	cin >> k;

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		sensor.push_back(input);
	}
	// 센서의 위치를 오름차순으로 정렬
	sort(sensor.begin(), sensor.end());

	// 이웃한 센서 간의 거리를 구하기
	for (int i = 0; i < n - 1; i++) {
		dist.push_back(abs(sensor.at(i) - sensor.at(i + 1)));
	}
	// 이웃한 센서 간의 거리값을 오름차순으로 정렬
	sort(dist.begin(), dist.end());

	// 센서 사이의 거리가 넓은 곳은 서로 다른 집중국이 담당하도록 함
	// 따라서, 이웃한 센서 간의 거리값들 중에 (집중국의 수 - 1)개를 큰 값부터 제거한 나머지를 모두 합산
	for (int i = 0; i < (int)dist.size() - (k - 1); i++) {
		answer += dist.at(i);
	}

	cout << answer;

	return 0;
}