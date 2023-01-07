#include <bits/stdc++.h>
using namespace std;

int alphabet[26];
int N;
bool isExist = false;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		alphabet[name[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (alphabet[i] >= 5) {
			cout << char('a' + i);
			isExist = true;
		}
	}
	if (!isExist) cout << "PREDAJA" << '\n';
	return 0;
}