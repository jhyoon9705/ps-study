// BOJ_1715 (https://www.acmicpc.net/problem/1715)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, deck;
	long long result = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> deck;
		pq.push(deck);
	}

	while (pq.size() > 1) {
		int subDeck = pq.top();
		pq.pop();
		subDeck += pq.top();
		pq.pop();
		result += subDeck;
		pq.push(subDeck);
	}
	
	cout << result;
}