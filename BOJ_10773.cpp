#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v;
	int k;
	int sum = 0;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			v.pop_back();
		}
		else {
			v.push_back(num);
		}
	}

	for (unsigned int j = 0; j < v.size(); j++) {
		sum += v[j];
	}

	cout << sum;
}