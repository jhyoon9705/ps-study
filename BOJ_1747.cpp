#include <bits/stdc++.h>

using namespace std;

int N;

bool isPrime(int num) {
	if (num < 2) return false;
	int temp = (int)sqrt(num);
	for (int i = 2; i <= temp; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

bool isPalindrome(int num) {
	string number = to_string(num);
	for (int i = 0; i <= number.length() - 1; i++) {
		if (number[i] == number[number.length() - 1 - i]) continue;
		else return false;
	}

	return true;
}

int main() {
	cin >> N;

	int number = N - 1;
	while (1) {
		number += 1;
		if (isPrime(number) && isPalindrome(number)) {
			cout << number;
			break;
		}

	}
	return 0;
}