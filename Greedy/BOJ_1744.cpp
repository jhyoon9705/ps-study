// BOJ_1744(¼ö ¹­±â) (https://www.acmicpc.net/problem/1744)
#include <bits/stdc++.h>

using namespace std;

int zero = 0;
int result = 0;
vector<int> positive, negative;

int solve() {
	sort(positive.begin(), positive.end(), greater<int>());
	sort(negative.begin(), negative.end());

	for (unsigned i = 0; i < positive.size() - (positive.size() % 2); i += 2) {
		result += positive[i] * positive[i + 1];

	}
	if (positive.size() % 2 == 1) {
		result += positive.back();
	}

	for (unsigned i = 0; i < negative.size() - (negative.size() % 2); i += 2) {
		result += negative[i] * negative[i + 1];

	}
	if (negative.size() % 2 == 1) {
		if (zero == 0) {
			result += negative.back();
		}
	}

	return result;
}

int main() {
	int n;


	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;

		if (k > 1) {
			positive.push_back(k);
		}
		else if (k == 1) {
			result += 1;
		}
		else if (k == 0) {
			zero++;
		}
		else {
			negative.push_back(k);
		}

	}

	cout << solve();

}