#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int cardNum;
	vector<long long> card;
	for (int i = 0; i < n; i++) {
		cin >> cardNum;
		card.push_back(cardNum);
	}

	sort(card.begin(), card.end());

	long long cardSum = 0;
	for (int j = 0; j < m; j++) {
		cardSum = card[0] + card[1];
		card[0] = cardSum;
		card[1] = cardSum;
		sort(card.begin(), card.end());
	}
	
	long long points = 0;
	for (int k = 0; k < (int)card.size(); k++) {
		points += card[k];
	}

	cout << points << endl;
}