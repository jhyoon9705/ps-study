#include <bits/stdc++.h>
using namespace std;

const int INF = 2000000002;
int n, input, l, r, mid, ret = INF, al, ar;
vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());	
	l = al = 0; r = ar = v.size() - 1;
	while (l < r) {
		if (abs(v[l] + v[r]) < ret) {
			ret = abs(v[l] + v[r]);
			al = l;
			ar = r;
		}
		if (v[l] + v[r] < 0) l++;
		else if (v[l] + v[r] > 0) r--;
		else break;	
	}
	cout << v[al] << " " << v[ar] << "\n";
	return 0;	
}