#include <bits/stdc++.h>

using namespace std;

char str[51];
bool isMinus;
int len, temp;
int sum = 0;

int main() {
	cin >> str;
	len = strlen(str);
	
	// 한번 -가 나오면 그 뒤로는 모두 뺄셈을 해주면 최솟값
	for (int i = 0; i <= len; i++) {
		if (str[i] == '+' || str[i] == '-' || i == len) {
			if (isMinus == false) {
				sum += temp;
				temp = 0;
			}
			else {
				sum -= temp;
				temp = 0;
			}
			if (str[i] == '-') {
				isMinus = true;
			}
		}
		else {
			temp *= 10; // 숫자 다음이 숫자인 경우 자리수 하나씩 올리기
			temp += str[i] - '0'; // char를 int로 변환
		}
	}
	cout << sum;

	return 0;
}