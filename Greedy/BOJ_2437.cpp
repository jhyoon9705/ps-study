// 1부터 K까지 무게를 모두 만들 수 있고 다음 추의 무게가 L(>K)일 경우,
// 1+L 부터 K+L 무게까지도 모두 만들 수 있음
#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1000];

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int result = 1;
	for (int i = 0; i < N; i++) {
	for (int i = 0; i < N; i++) {
		if (arr[i] > result) {
			break;
		}
		result += arr[i];
	}

	cout << result;
	return 0;
}