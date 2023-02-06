#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'p') {
			if (s[i + 1] == 'i') i++;
			else {
				cout << "NO" << "\n";
				return 0;
			}
		}
		else if (s[i] == 'k') {
			if (s[i + 1] == 'a') i++;
			else {
				cout << "NO" << "\n";
				return 0;
			}
		}
		else if (s[i] == 'c') {
			if (s[i + 1] == 'h' && s[i + 2] == 'u') i += 2;
			else {
				cout << "NO" << "\n";
				return 0;
			}
		}
		else {
			cout << "NO" << "\n";
			return 0;
		}	
	}
	cout << "YES" << "\n";
	return 0;
}