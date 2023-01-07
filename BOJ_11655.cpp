#include <bits/stdc++.h>
using namespace std;

string s, rot;

void rotFunc(char c) {
	if (c >= 'a' && c <= 'z') {
		if (c + 13 > 'z') rot += c - 13;
		else rot += c + 13;
	}
	else if (c >= 'A' && c <= 'Z') {
		if (c + 13 > 'Z') rot += c - 13;
		else rot += c + 13;
	}
	else rot += c;
}

int main() { 
	getline(cin, s);
	for (char c : s) {
		rotFunc(c);
	}
	cout << rot << '\n';
	return 0;
}