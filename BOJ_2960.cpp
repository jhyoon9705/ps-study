// Eratosthenes' sieve
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, iter, p;
	int count = 0;
	int result = 0;
	vector<int> v;

	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		v.push_back(i);
	}

	iter = 0;

	while (count != k) {
		p = v[iter]; // find small number (=p)
		v[iter] = 0; // delete p
		count++; // deleting count (+ 1)

		if (count == k) {
			result = p;
			break;
		}
		int j = 1;
				
		while (j <= (int)((n - 2) / p)) {
			if (v[iter + j * p] != 0) {
				result = v[iter + j * p];
				v[iter + j * p] = 0;
				count++;

				if (count == k) {
					break;
				}
			}
			j++;
		}
	
		while (v[iter] == 0) {
			iter++;
		}
	}

	cout << result;
}