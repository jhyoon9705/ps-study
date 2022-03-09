#include <bits/stdc++.h>

using namespace std;

int palindrome(string s, int check) {
	int frontIndex = 0;
	int backIndex = s.length() - 1;

	while (frontIndex < backIndex) {
		if (s[frontIndex] != s[backIndex]) {
			if (check == 0) {
				int len = backIndex - frontIndex;
				if (palindrome(s.substr(frontIndex + 1, len), 1) == 0 || palindrome(s.substr(frontIndex, len), 1) == 0)
					return 1; //유사회문
				else
					return 2; //비유사회문
			}
			else
				return 2;
		}
		frontIndex++;
		backIndex--;
	}
	return 0;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		cout << palindrome(s, 0) << "\n";
	}

	return 0;
}