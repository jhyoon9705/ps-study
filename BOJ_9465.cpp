// 시작점은 [0][0] 또는 [1][0]
// 바로 대각선으로 가거나 한 줄 건너뛰고 그 다음 대각선으로 가는 경우로 나뉨
// 둘 중에 큰 값을 선택

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sticker[2][100001];
		sticker[0][0] = sticker[1][0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> sticker[0][i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> sticker[1][i];
		}

		for (int i = 2; i <= n; i++) {
			sticker[0][i] = max(sticker[1][i - 1], sticker[1][i - 2]) + sticker[0][i];
			sticker[1][i] = max(sticker[0][i - 1], sticker[0][i - 2]) + sticker[1][i];
		}
		int answer = max(sticker[1][n], sticker[0][n]);
		cout << answer << '\n';
	}

	return 0;
}