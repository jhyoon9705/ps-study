#include <bits/stdc++.h>
using namespace std;

int N, K, input, temp;
int psum[100001], ret = -10000004;

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> input;
		psum[i] = psum[i - 1] + input;
	}
	
	for (int i = K; i <= N; i++) {
		ret = max(ret, psum[i] - psum[i - K]);
	}
	cout << ret << '\n';
	return 0;
}