#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<pair<long, long>> v;
	int answer = 0;
	int index, maxNum;
	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;

		v.push_back({ start, end });
	}
	sort(v.begin(), v.end());

	index = v[0].first;
	maxNum = v[v.size() - 1].second;

	for (int i = 0; i < N; i++) {
		int hereStart = v[i].first;
		int hereEnd = v[i].second;

		if (index < hereStart) {
			index = hereStart;
		}

		while (index < hereEnd) {
			index += L;
			answer++;
		}
		
	}
	cout << answer;

	return 0;

}