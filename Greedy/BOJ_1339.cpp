// 각 자리수 별로 숫자를 매기고, 가장 큰 숫자부터 9부터 순서대로 할당
// ex) GCF + ACDEB
// A = 10000 * 9
// C = 1010 * 8
// ...
#include <bits/stdc++.h>

using namespace std;

int alphabet[26];
int n;
vector<string> words;
int result = 0;

int main() {
	cin >> n;

	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		words.push_back(input);
	}

	for (int i = 0; i < n; i++) {
		int pow = 1;
		for (int j = (int)words[i].size() - 1; j >= 0; j--) {
			int value = words[i][j] - 'A';
			alphabet[value] += pow;
			pow *= 10;
		}
	}
	sort(alphabet, alphabet + 26);

	int num = 9;
	for (int i = 25; i >= 0; i--) {
		if (alphabet[i] == 0) break;
		result += (alphabet[i] * num);
		num--;
	}

	cout << result;
	return 0;
}