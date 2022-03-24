#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
	return a.first > b.first;
}

int main() {
	int totalPay = 0;
	int num;
	cin >> num;

	vector<pair<int, int>> v;

	int dInput, pInput;
	int d, p;
	int lecture[10000] = { 0 }; // 강연 스케줄 배열(0이면 없음, 1이면 있음)

	for (int i = 0; i < num; i++) {
		cin >> pInput >> dInput;
		v.push_back(make_pair(pInput, dInput));
	}

	// 강연료가 많은 순으로 정렬
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < num; i++) {
		d = v[i].second;
		p = v[i].first;

		while (d != 0) { // 기한 안의 날짜 중에서 빈 날짜가 있을 때까지 탐색
			if (lecture[d - 1] == 0) { // 비어있는 날짜가 있으면
				lecture[d - 1] = 1; // 강연을 하고
				totalPay += p; // 강연료를 받음
				break;
			}
			d--;
		}
	}

	cout << totalPay << endl;

}