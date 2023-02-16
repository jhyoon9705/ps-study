#include<bits/stdc++.h>
using namespace std;

string s, ret = "";

int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (ret.length() < 3) ret += s[i];
		else {
			if (s[i] == 'P' && ret.substr(ret.length() - 3) == "PPA") {
				ret.erase(ret.length()-3);				
			}
			ret += s[i];
		}
	}
	if (ret == "PPAP" || ret == "P") cout << "PPAP" << "\n";
	else cout << "NP" << "\n";
	return 0;
}