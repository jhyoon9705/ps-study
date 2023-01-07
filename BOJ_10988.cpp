#include <bits/stdc++.h>
using namespace std;

int main() {
	string word, temp;
	cin >> word;
	temp = word;
	reverse(temp.begin(), temp.end());
	if (temp == word) cout << 1 << '\n';
	else cout << 0 << '\n';

	return 0;
}

/* int main() {
	string word;
	int answer = 1;
	cin >> word;

	for (int i = 0; i < (int)word.size() / 2; i++) {
		if (word[i] != word[(int)word.size() - 1 - i]) answer = 0;
	}
	cout << answer << '\n';
	return 0;
} */