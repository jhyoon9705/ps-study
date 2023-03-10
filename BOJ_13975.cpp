#include <bits/stdc++.h>
using namespace std;

int t, k, input;
long long ret, a, b;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
	cin >> t;
	while (t--) {
		ret = 0;
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> input;
			pq.push(input);
		}
		while(pq.size()) {
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			ret += (a + b);
			if (pq.size()) pq.push(a + b);
		}		
		cout << ret << "\n";
	}
	return 0;
}