// �������� [0][0] �Ǵ� [1][0]
// �ٷ� �밢������ ���ų� �� �� �ǳʶٰ� �� ���� �밢������ ���� ���� ����
// �� �߿� ū ���� ����

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