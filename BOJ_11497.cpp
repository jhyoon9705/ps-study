#include <bits/stdc++.h>

using namespace std;

// �볪���� ���̸� ������������ ���� ��,
// ���ʺ��� ���������� �ϳ��� �ǳʶٸ� ��ġ�ϰ�(¦�� index),
// �ٽ� ���������� �������� �ϳ��� �ǳʶٸ� ��ġ�Ѵ�(Ȧ�� index)
// ���������� ������ �� ���� �볪�� ���̸� ���ذ��� �ִ밪�� ã�´�.
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