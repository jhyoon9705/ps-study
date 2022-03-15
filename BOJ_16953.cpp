#include <bits/stdc++.h>

using namespace std;

// 결과값에서 처음 값으로 거꾸로 진행
// 일의 자리수가 1이면 1을 떼고, 짝수면 나누기 2, 둘 다 아니면 연산 불가 처리
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