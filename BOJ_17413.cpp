#include <bits/stdc++.h>

using namespace std;

int main() {
	string original;
	string result = "";
	vector<char> temp;
	int wordLength;

	getline(cin, original);

	for (int i = 0; i < (int)original.size(); i++) {
		if (original.at(i) == '<') {
			result.push_back(original.at(i));
			i++;
			while (original.at(i) != '>') {
				result.push_back(original.at(i));
				i++;
			}
			result.push_back(original.at(i));
		}

		else {

			while (i <  (int)original.size() && original.at(i) != ' ' && original.at(i) != '<') {
				temp.push_back(original.at(i));
				i++;
			}

			wordLength = (int)temp.size();

			for (int j = 0; j < wordLength; j++) {
				result.push_back(temp.back());
				temp.pop_back();
			}
			
			if (i < (int)original.size() && original.at(i) == ' ') {
				result.push_back(' ');
			}
			else if (i < (int)original.size() && original.at(i) == '<') {
				i--;
			}
	
		}
	}
	for (int k = 0; k < (int)result.size(); k++) {
		cout << result[k];
	}

}