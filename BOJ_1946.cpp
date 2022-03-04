// Base on those who fail
#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v1, v2, result;
	int t, n;
	int test1, test2;
	int counter = 0;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> test1 >> test2;
			v1.push_back(test1);
			v2.push_back(test2);
		}

		int min1_index = min_element(v1.begin(), v1.end()) - v1.begin();
		int min2_index = min_element(v2.begin(), v2.end()) - v2.begin();
		int cutline2 = v2[min1_index];
		int cutline1 = v1[min2_index];

		for (int a = 0; a < v1.size(); a++) {
			if (cutline2 < v2[a]) {
				v1[a] = 0;
				v2[a] = 0;
			}
		}

		for (int b = 0; b < v2.size(); b++) {
			if (cutline1 < v1[b]) {
				v1[b] = 0;
				v2[b] = 0;
			}
		}

		for (int c = 0; c < v1.size(); c++) {
			if (v1[c] == 0 && v2[c] == 0) {
				counter++;
			}
		}

		cout << v1.size() - counter << endl;

		counter = 0;

		v1.clear();
		v2.clear();
	}

}

/*
// Base on the successful candidates

#include <bits/stdc++.h>
using namespace std;


int T, N;
int cnt_array[21];
pair<int, int> score[100000];
int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> score[j].first >> score[j].second;
		}

		sort(score, score + N); //first를 기준으로 오름차순으로 정렬


		int max_score = score[0].second;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (score[i].second <= max_score) {
				cnt++;
				max_score = score[i].second;
			}
		}

		cnt_array[i] = cnt;

	}

	for (int i = 0; i < T; i++) {
		cout << cnt_array[i] << endl;
	}


	return 0;
}*/