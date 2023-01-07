#include <bits/stdc++.h>

using namespace std;

int k;
vector<char> v;
long long maxNum = -9999999999;
long long minNum = 9999999999;
string M, m;
bool visited[10];

bool isValid(int a, int b, int order) {
	if (v[order] == '>') {
		return a > b;
	}
	else {
		return a < b;
	}
}

void func(int count, string result) {
	if (count == k + 1) {
		long long temp = stol(result);
		if (temp > maxNum) {
			M = result;
			maxNum = temp;
		}
		if (temp < minNum) {
			m = result;
			minNum = temp;
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (visited[i] == true) continue;
		if (count == 0) {
			visited[i] = true;
			result += to_string(i);
			func(count + 1, result);
			// back-tracking
			result.pop_back();
			visited[i] = false;
		}
		else {
			int tmp = result[count - 1] - '0';
			if (isValid(tmp, i, count - 1)) {
				visited[i] = true;
				result += to_string(i);
				func(count + 1, result);
				// back-tracking
				result.pop_back();
				visited[i] = false;
			}
			else {
				continue;
			}

		}
	}
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		char input;
		cin >> input;
		v.push_back(input);
	}

	func(0, "");
	cout << M << '\n';
	cout << m << '\n';

	return 0;
}