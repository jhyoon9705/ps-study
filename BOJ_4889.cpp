#include <bits/stdc++.h>

using namespace std;

int main() {
	int testCase = 0;

	while (1) {
		testCase++;
		vector<char> v;
		int result = 0;
		string input;
		cin >> input;

		if (input[0] == '-') break;

		for (int i = 0; i < input.length(); i++) {
			if (v.empty()) v.push_back(input[i]);
			else {
				if (v.back() == '{' && input[i] == '}') {
					v.pop_back();
				}
				else {
					v.push_back(input[i]);
				}
			}
		}

		while (!v.empty()) {
			char first = v.back();
			v.pop_back();
			char second = v.back();
			v.pop_back();

			if (first == second) result += 1;
			else result += 2;

		}

		cout << testCase << ". " << result << '\n';
	}
	return 0;
}