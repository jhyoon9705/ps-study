#include <bits/stdc++.h>

using namespace std;

// 통나무의 높이를 오름차순으로 정렬 후,
// 왼쪽부터 오른쪽으로 하나씩 건너뛰며 배치하고(짝수 index),
// 다시 끝에서부터 왼쪽으로 하나씩 건너뛰며 배치한다(홀수 index)
// 마지막으로 인접한 두 개의 통나무 높이를 비교해가며 최대값을 찾는다.
int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, input;
		int result = -1;
		vector<int> woods, sequence;
		
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> input;
			woods.push_back(input);
		}

		sort(woods.begin(), woods.end());

		if ((int)woods.size() % 2 == 0) {
			for (int k = 0; k < (int)woods.size() / 2; k++) {
				sequence.push_back(woods[k * 2]);
			}
			for (int k = 0; k < (int)woods.size() / 2; k++) {
				sequence.push_back(woods[(int)woods.size() - 1 - (k * 2)]);
			}
		}
		else {
			for (int k = 0; k < ((int)woods.size() + 1) / 2 ; k++) {
				sequence.push_back(woods[k * 2]);
			}
			for (int k = 0; k < ((int)woods.size() - 1) / 2; k++) {
				sequence.push_back(woods[(int)woods.size() - 2 - (k * 2)]);
			}
		}

		int a = 0;
		int b = 1;
		int gap, rotateGap;

		while (b != sequence.size()) {
			gap = abs(sequence[b] - sequence[a]);
			if (gap > result) {
				result = gap;
			}
			a++;
			b++;
		}

		rotateGap = abs(sequence[a] - sequence[0]);
		if (rotateGap > result) {
			result = rotateGap;
		}

		cout << result << endl;

	}
}