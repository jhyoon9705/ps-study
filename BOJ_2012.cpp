#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	long long result = 0;
	vector<int> rank;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		rank.push_back(input);
	}

	sort(rank.begin(), rank.end());

	for (int i = 0; i < n; i++) {
		int myRank = i + 1;
		result += abs(myRank - rank[i]);
	}

	cout << result;
	return 0;
}