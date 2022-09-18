#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	int counter = 0;
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	while (true) {
		if (v.size() == 1) break;

		v[v.size() - 2] += v[v.size() - 1];
		v.pop_back();
		counter++;
		v[0]--;

		if (v[0] == 0) {
			for (int i = 0; i < v.size() - 1; i++) {
				v[i] = v[i + 1];
			}
			v.pop_back();
		}
	}

	cout << counter;

	return 0;
}