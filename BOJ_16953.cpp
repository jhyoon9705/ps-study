#include <bits/stdc++.h>

using namespace std;

// ��������� ó�� ������ �Ųٷ� ����
// ���� �ڸ����� 1�̸� 1�� ����, ¦���� ������ 2, �� �� �ƴϸ� ���� �Ұ� ó��
int main() {
	int A, B;
	cin >> A >> B;

	int counter = 1;

	while (A < B) {
		if (B % 10 == 1) {
			B /= 10;
			counter++;
		}
		else if(B % 2 == 0){
			B /= 2;
			counter++;
		}
		else {
			counter = -1;
			break;
		}
	}

	if (A == B) {
		cout << counter << endl;
	}
	else {
		cout << -1 << endl;
	}
}