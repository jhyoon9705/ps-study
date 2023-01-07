#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> v;
int answer = 1000000000;

void func(int idx, int totalS, int totalB) {
	if (idx == N) {
		if (totalB != 0) {
			answer = min(answer, abs(totalS - totalB));
		}
		return;
	}
	func(idx + 1, totalS, totalB); // idx��° ��Ḧ ���� �ʴ� ���
	func(idx + 1, totalS * v[idx].first, totalB + v[idx].second); // idx��° ��Ḧ �ִ� ���
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int S, B;
		cin >> S >> B;
		v.push_back({ S, B });
	}

	func(0, 1, 0);

	cout << answer;

	return 0;
}