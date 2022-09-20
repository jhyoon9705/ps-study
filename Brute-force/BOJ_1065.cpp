#include <bits/stdc++.h>

using namespace std;

int N;
int answer = 0;

bool isHansu(int num) {
	if (num < 10) {
		return true;
	}
	else {
		string number = to_string(num);
		int gap = number[0] - number[1];
		for (int i = 1; i < (int)number.length()-1; i++) {
			if (number[i] - number[i + 1] != gap) {
				return false;
			}
		}
		return true;
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (isHansu(i) == true) answer++;
	}
	
	cout << answer;

	return 0;
}