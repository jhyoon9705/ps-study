#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> v;
int mt[101];

int main() {
	int result = 0;

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < K; i++) {
		bool pluggedIn = false;

		// 이미 기기가 멀티탭에 꽂혀있는 경우
		for (int j = 0; j < N; j++) { // 멀티탭 구멍 개수만큼 탐색
			if (mt[j] == v[i]) {
				pluggedIn = true;
				break;
			}
		}
		if (pluggedIn) continue;

		// 비어있는 멀티탭의 구멍 확인(<-멀티탭에 꽂혀있지 않은 경우)
		for (int j = 0; j < N; j++) {
			if (!mt[j]) {
				mt[j] = v[i]; // 찾은 빈 구멍에 기기 꽂기
				pluggedIn = true;
				break;
			}
			
		}
		if (pluggedIn) continue;

		// 가장 나중에 다시 사용되거나 앞으로 사용되지 않을 기기 찾기(<-비어있는 구멍도 없고 아직 꽂혀있지도 않은 경우)
		int idx, deviceIdx = -1;
		for (int j = 0; j < N; j++) {
			int lastIdx = 0;
			for (int k = i + 1; k < K; k++) {
				if (mt[j] == v[k]) break;
				lastIdx++;
			}

			if (lastIdx > deviceIdx) {
				idx = j;
				deviceIdx = lastIdx;
			}
		}
		result++;

		// 위에서 찾은 기기를 빼고 새로운 기기를 꽂음
		mt[idx] = v[i];
	}
	cout << result;
	return 0;
}