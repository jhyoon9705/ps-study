// 1���� K���� ���Ը� ��� ���� �� �ְ� ���� ���� ���԰� L(>K)�� ���,
// 1+L ���� K+L ���Ա����� ��� ���� �� ����
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