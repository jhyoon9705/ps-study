#include <bits/stdc++.h>
using namespace std;

int M, N;
string temp;
map<string, int> mp;
string a[100004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		mp[temp] = i + 1;
		a[i + 1] = temp;
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (atoi(temp.c_str()) == 0) cout << mp[temp] << '\n'; // string
		else cout << a[atoi(temp.c_str())] << '\n'; // number
	}
	return 0;	
}