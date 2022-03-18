#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int steps = 0;
	vector<int> negative, positive;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		// 양수 좌표, 음수 좌표 따로 분리
		if (input > 0) {
			positive.push_back(input);
		}
		else {
			negative.push_back(input);
		}
	}

	
	if (!positive.empty()) {
		sort(positive.begin(), positive.end());
	}
	if (!negative.empty()) {
		sort(negative.begin(), negative.end());
	}

	if (positive.empty()) {
		steps += abs(negative[0]);
		if ((int)negative.size() <= M) {
			negative.clear();
		}
		else {
			for (int i = 0; i < M; i++) {
				negative.erase(negative.begin());
			}
			while (!negative.empty()) {
				if ((int)negative.size() <= M) {
					steps += abs(negative[0] * 2);
					negative.clear();
				}
				else {
					steps += abs(negative[0] * 2);
					for (int j = 0; j < M; j++) {
						negative.erase(negative.begin());
					}
				}
			}
		}
		cout << steps << endl;
		return 0;
	}

	if (negative.empty()) {
		steps += positive.back();
		if ((int)positive.size() <= M) {
			positive.clear();
		}
		else {
			for (int i = 0; i < M; i++) {
				positive.pop_back();
			}
			while (!positive.empty()) {
				if ((int)positive.size() <= M) {
					steps += (positive.back() * 2);
					positive.clear();
				}
				else {
					steps += (positive.back() * 2);
					for (int j = 0; j < M; j++) {
						positive.pop_back();
					}
				}
			}
		}
		cout << steps << endl;
		return 0;
	}

	// 양쪽 끝값중 절댓값이 큰쪽은 마지막에 편도로만 진행, 아닌 쪽은 끝에서부터 M만큼씩
	if (positive.at(positive.size() - 1) >= abs(negative[0])) {
		steps += positive.back();
		if ((int)positive.size() <= M) {
			positive.clear();
		}
		else {
			for (int i = 0; i < M; i++) {
				positive.pop_back();
			}
			while (!positive.empty()) {
				if ((int)positive.size() <= M) {
					steps += (positive.back() * 2);
					positive.clear();
				}
				else {
					steps += (positive.back() * 2);
					for (int j = 0; j < M; j++) {
						positive.pop_back();
					}
				}
			}
		}

		while (!negative.empty()) {
			if ((int)negative.size() <= M) {
				steps += abs(negative[0] * 2);
				negative.clear();
			}
			else {
				steps += abs(negative[0] * 2);
				negative.erase(negative.begin(), negative.begin() + M);
			}
		}
	}
	
	else {
		steps += abs(negative[0]);
		if ((int)negative.size() <= M) {
			negative.clear();
		}
		else {
			for (int i = 0; i < M; i++) {
				negative.erase(negative.begin());
			}
			while (!negative.empty()) {
				if ((int)negative.size() <= M) {
					steps += abs(negative[0] * 2);
					negative.clear();
				}
				else {
					steps += abs(negative[0] * 2);
					for (int j = 0; j < M; j++) {
						negative.erase(negative.begin());
					}
				}
			}
		}

		while (!positive.empty()) {
			if ((int)positive.size() <= M) {
				steps += (positive.back() * 2);
				positive.clear();
			}
			else {
				steps += (positive.back() * 2);
				for (int j = 0; j < M; j++) {
					positive.pop_back();
				}
			}
		}
	}

	std::cout << steps << endl;
}