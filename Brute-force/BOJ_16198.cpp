#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v, sum;
int answer = 0;

void func(int tempSum) {
	if (v.size() == 2) {
		answer = max(answer, tempSum);
		return;
	}

	for (int i = 1; i < v.size() - 1; i++) {
		int energy = v[i - 1] * v[i + 1];
		int temp = v[i];

		v.erase(v.begin() + i);
		func(tempSum + energy);
		v.insert(v.begin() + i, temp); // back-tracking
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	func(0);

	cout << answer;
	return 0;
}