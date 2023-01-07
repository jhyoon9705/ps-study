#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;

		v[i].first--;
	}

	sort(v.begin(), v.end());

	int result = 0;
	int idx = N - 1;
	priority_queue<int> pq;

	// 데드라인이 높은 순서
	for (int i = N - 1; i >= 0; i--)
	{
		for (; idx >= 0 && v[idx].first == i; idx--)
		{
			pq.push(v[idx].second);
		}

		if (!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}
	}

	cout << result << endl;

	return 0;
}

// 시간 초과 code
// #include <bits/stdc++.h>
// 
// using namespace std;
// 
// bool compare(pair<int, int>& a, pair<int, int>& b) {
// 	if (a.second == b.second) {
// 		return a.first < b.first;
// 	}
// 	else {
// 		return a.second > b.second;
// 	}
// }
// 
// int main() {
// 	int N;
// 	cin >> N;
// 
// 	int deadline, cup;
// 	vector<pair<int, int>> hw;
// 
// 	int counter = 0;
// 	vector<int> assign;
// 
// 	for (int i = 0; i < N; i++) {
// 		cin >> deadline >> cup;
// 		hw.push_back(make_pair(deadline, cup));
// 		assign.push_back(0);
// 	}
// 	
// 	sort(hw.begin(), hw.end(), compare);
// 
// 	int currentDeadline, currentCup;
// 
// 	for (int j = 0; j < N; j++) {
// 		currentDeadline = hw[j].first;
// 		currentCup = hw[j].second;
// 
// 		for (int k = currentDeadline - 1; k >= 0; k--) {
// 			if (assign[k] == 0) {
// 				assign[k] = 1;
// 				counter += currentCup;
// 				break;
// 			}
// 		}
// 	}
// 
// 	cout << counter << endl;
// }