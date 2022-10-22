#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
bool check[2000001];

void func(int x, int sum) {
	check[sum] = true;
	if (x == N) return;
	else {
		func(x + 1, sum);
		func(x + 1, sum + v[x]);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	func(0, 0);

	int j = 1;
	while (check[j] == true) j++;
	cout << j;

	return 0;
}