#include <bits/stdc++.h>

using namespace std;

char str[51];
bool isMinus;
int len, temp;
int sum = 0;

int main() {
	cin >> str;
	len = strlen(str);
	
	// �ѹ� -�� ������ �� �ڷδ� ��� ������ ���ָ� �ּڰ�
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
			temp *= 10; // ���� ������ ������ ��� �ڸ��� �ϳ��� �ø���
			temp += str[i] - '0'; // char�� int�� ��ȯ
		}
	}
	cout << sum;

	return 0;
}