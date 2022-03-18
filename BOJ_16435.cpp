#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, L;
	cin >> N >> L;

	vector<int> fruits;
	int input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		fruits.push_back(input);
	}

	sort(fruits.begin(), fruits.end());

	for (int j = 0; j < N; j++) {
		if (L >= fruits[j]) {
			L++;
		}
		else break;
	}

	cout << L << endl;

}