#include <bits/stdc++.h>

using namespace std;

char palindrome[50];
bool isFull[50];
int alphabetNum[26];
int wordLen, idx = 0;
string word;

int main() {
	cin >> word;

	wordLen = (int)word.size();

	for (int i = 0; i < wordLen; i++) {
		alphabetNum[word.at(i) - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		while (alphabetNum[i] >= 2) {
			palindrome[idx] = 'A' + i;
			isFull[idx] = true;
			palindrome[wordLen - 1 - idx] = 'A' + i;
			isFull[wordLen - 1 - idx] = true;
			idx++;
			alphabetNum[i] -= 2;
		}
		if (alphabetNum[i] == 1) {
			if (isFull[wordLen / 2]) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			palindrome[wordLen / 2] = 'A' + i;
			isFull[wordLen / 2] = true;
			alphabetNum[i] -= 1;
		}
	}

	for (int i = 0; i < wordLen; i++) {
		cout << palindrome[i];
	}

	return 0;
}