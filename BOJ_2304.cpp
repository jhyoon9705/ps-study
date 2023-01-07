#include <bits/stdc++.h>

using namespace std;

int pillar[1001];
vector<pair<int, int>> v;

int main() {
	int N;
	int result = 0;
	int maxPosition, maxHeight = -1;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int location, height;
		cin >> location >> height;
		pillar[location] = height;
		if (maxHeight < height) {
			maxPosition = location;
			maxHeight = height;
		}
	}

	int leftMax = 0;
	for (int i = 1; i < maxPosition; i++) {
		leftMax = max(leftMax, pillar[i]);
		result += leftMax;
	}

	int rightMax = 0;
	for (int i = 1000; i > maxPosition; i--) {
		rightMax = max(rightMax, pillar[i]);
		result += rightMax;
	}

	result += maxHeight;

	cout << result;
	return 0;
}