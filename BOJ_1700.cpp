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

		// �̹� ��Ⱑ ��Ƽ�ǿ� �����ִ� ���
		for (int j = 0; j < N; j++) { // ��Ƽ�� ���� ������ŭ Ž��
			if (mt[j] == v[i]) {
				pluggedIn = true;
				break;
			}
		}
		if (pluggedIn) continue;

		// ����ִ� ��Ƽ���� ���� Ȯ��(<-��Ƽ�ǿ� �������� ���� ���)
		for (int j = 0; j < N; j++) {
			if (!mt[j]) {
				mt[j] = v[i]; // ã�� �� ���ۿ� ��� �ȱ�
				pluggedIn = true;
				break;
			}
			
		}
		if (pluggedIn) continue;

		// ���� ���߿� �ٽ� ���ǰų� ������ ������ ���� ��� ã��(<-����ִ� ���۵� ���� ���� ���������� ���� ���)
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

		// ������ ã�� ��⸦ ���� ���ο� ��⸦ ����
		mt[idx] = v[i];
	}
	cout << result;
	return 0;
}