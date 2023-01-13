#include <bits/stdc++.h>
using namespace std;

int n;
int num = 666;

int main() {
	cin >> n;
	while (n > 0) {
		if (to_string(num).find("666") != string::npos) n--;
		num++;
	}
	cout << num - 1 << '\n';
	return 0;
}