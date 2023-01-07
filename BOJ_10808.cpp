#include <bits/stdc++.h>
using namespace std;

string s;
int arr[26];
int main() {
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++) arr[s[i] - 'a']++;
	for (int i : arr) cout << i << " ";
	return 0;
}