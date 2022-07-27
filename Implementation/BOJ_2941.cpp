#include <bits/stdc++.h>

using namespace std;

int main() {
	int count = 0;
	string s;
	
	cin >> s;

	for (int i = 0; i < (int)s.size(); i++) {
		if (i == (int)s.size() - 1) {
			count++;
			break;
		}
				
		switch (s[i]) {
		case 'c':
			if (s[i + 1] == '=' || s[i + 1] == '-') i++;
			break;
		case 'd':
			if (s[i + 1] == 'z' && s[i + 2] == '=') i += 2;
			else if (s[i + 1] == '-') i++;
			break;
		case 'l':
			if (s[i + 1] == 'j') i++;
			break;
		case 'n':
			if (s[i + 1] == 'j') i++;
			break;
		case 's':
			if (s[i + 1] == '=') i++;
			break;
		case 'z':
			if (s[i + 1] == '=') i++;
			break;
		default:
			break;
		}

		count++;
	
	}

	cout << count;
	
}