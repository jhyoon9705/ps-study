#include <bits/stdc++.h>
using namespace std;

int N, M, input;
int nums[150001];
vector<int> v;
int ret = 0;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];		
	}
	sort(v.begin(), v.end());

	if (M > 200000) cout << 0 << '\n';
	else {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (nums[i] + nums[j] == M) ret++;
			}
		}
		cout << ret << '\n';
	}
	
	return 0;
}