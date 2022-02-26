#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int n;
int result = 0;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i *= 10)
		result += n - i + 1;
	printf("%d", result);
	return 0;
}

// 시간 초과 코드
//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	int n, k;
//	int digit = 0;
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++) {
//		k = i;
//		while (k != 0) {
//			k /= 10;
//			digit++;
//		}
//	}
//
//	printf("%d", digit);
//}

