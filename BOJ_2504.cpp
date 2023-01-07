#include <bits/stdc++.h>

using namespace std;
vector<char> v;

int main() {
	string input;
	cin >> input;

	int temp = 1;
	int answer = 0;
	for (int i = 0; i < (int)input.size(); i++) {
		if (input[i] == '(') {
			temp *= 2;
			v.push_back('(');
		}
		else if (input[i] == '[') {
			temp *= 3;
			v.push_back('[');
		}
		else if (input[i] == ')') {
			if (v.empty() || v.back() != '(') {
				answer = 0;
				break;
			}
			if (input[i - 1] == '(') {
				answer += temp;
			}
			v.pop_back();
			temp /= 2;
		}
		else {
			if (v.empty() || v.back() != '[') {
				answer = 0;
				break;
			}
			if (input[i - 1] == '[') {
				answer += temp;
			}
			v.pop_back();
			temp /= 3;
		}
	}

	if (!v.empty()) answer = 0;

	cout << answer;
	return 0;
}