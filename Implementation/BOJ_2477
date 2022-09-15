// 1번째부터 6번째까지 탐색하며 이번 변과 다음 변의 곱들 중 가장 큰 값을 저장
// (i+3)%6과 (i+4)&6번째 변을 곱한 값을 위의 값에서 빼줌
// (i+3)%6번째, (i+4)%6번째 값은 i번째 인덱스가 가장 큰 가로와 세로일 때 가장 작은 가로와 세로
#include <bits/stdc++.h>

using namespace std;

int main() {
	int perNum, answer = 0;
	int square = 1;
	vector<pair<int, int>> v;
	cin >> perNum;

	for (int i = 0; i < 6; i++) {
		int direction, length;
		cin >> direction >> length;

		v.push_back({ direction, length });
	}

	for (int i = 0; i < 6; i++) {
		int current = v[i].second * v[(i + 1) % 6].second;

		if (square == 1 || current > square) {
			square = current;
			answer = (square - v[(i + 3) % 6].second * v[(i + 4) % 6].second) * perNum;
		}
	}
	cout << answer;

	return 0;
}
