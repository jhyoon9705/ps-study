#include <bits/stdc++.h>

using namespace std;

int n, w, L;
int onBridge = 0;
int order = 0;
int answer = 0;
vector<int> truck;
queue<int> q;

int main() {
	cin >> n >> w >> L;
	
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		truck.push_back(input);
	}

	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) { // 다리가 꽉 찬 경우
				onBridge -= q.front(); // 맨 앞에 있는 트럭을 다리 밖으로 보내고,
				q.pop(); // 다리 위 트럭 queue에서 제거
			}

			if (onBridge + truck.at(i) <= L) break; // 다리 위에 다음 트럭을 올릴 수 있는 경우에는 반복문을 빠져나가서 다리 위에 트럭 올리기

			q.push(0); // 다리 위에 다음 트럭을 못 올리면 그 timing은 그냥 통과(무게가 0인 트럭)
			answer++; // 시간 1 증가
		}
		q.push(truck.at(i)); // 다리 위에 트럭 올리기
		onBridge += truck.at(i); // 다리 위의 트럭들 무게 계산
		answer++; // 시간 1 증가
	}
	cout << answer + w;
	
	return 0;
}