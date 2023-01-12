#include <bits/stdc++.h>
using namespace std;

char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };

bool isVowel(char c) {
	bool ret = false;
	for (char v : vowel) {
		if (v == c) ret = true;
	}
	return ret;
}

bool func1(string s) {
	bool ret = false;
	for (int i = 0; i < 5; i++) {
		if (s.find(vowel[i]) != string::npos) {
			ret = true;
			break;
		}
	}
	return ret;
}

bool func2(string s) {
	int num = 0;
	bool ret = true;
	if (s.size() <= 2) return true;
	for (int i = 0; i < s.size() - 2; i++) {
		if (isVowel(s[i]) == isVowel(s[i + 1]) && isVowel(s[i + 1]) == isVowel(s[i + 2])) ret = false;
	}
	return ret;
}

bool func3(string s) {
	bool ret = true;
	if (s.size() == 1) return true;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]) {
			if (s[i] != 'e' && s[i] != 'o') ret = false;
		}
	}
	return ret;
}

int main() {
	string input;
	while (1) {
		cin >> input;
		if (input == "end") break;
		if (func1(input) && func2(input) && func3(input)) cout << '<' << input << '>' << " is acceptable." << '\n';
		else cout << '<' << input << '>' << " is not acceptable." << '\n';
	}
	return 0;
}