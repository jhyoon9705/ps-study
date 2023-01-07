#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;
int D, K;
int aAns, bAns;

int main() {
	cin >> D >> K;
	a.push_back(1);
	b.push_back(0);
	a.push_back(0);
	b.push_back(1);

	for (int i = 2; i < D; i++) {
		a.push_back(a[i - 2] + a[i - 1]);
		b.push_back(b[i - 2] + b[i - 1]);
	}

	int aNum = a.back();
	int bNum = b.back();

	for (int i = K / bNum; i >= 0; i--) {
		int temp = K - (bNum * i);
		bAns = i;
		if (temp != 0 && temp % aNum == 0) {
			aAns = temp / aNum;
			break;
		}
	}

	cout << aAns << '\n' << bAns;
	return 0;
}