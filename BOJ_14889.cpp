// bit masking
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int s[21][21], ret = INF, n;

int solve(vector<int>& a, vector<int>& b) {
	pair<int, int> ret;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			if (i == j) continue;
			ret.first += s[a[i]][a[j]];
			ret.second += s[b[i]][b[j]];
		}
	}
	return abs(ret.first - ret.second);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 0; i < (1 << n); i++) {
		if (__builtin_popcount(i) != n / 2) continue; // msvc: __popcnt(i) »ç¿ë
		vector<int> start, link;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) start.push_back(j);
			else link.push_back(j);
		}
		ret = min(ret, solve(start, link));
	}
	cout << ret << '\n';
	return 0;
}

/*#include <bits/stdc++.h>

using namespace std;

int point[21][21];
bool checker[22];
int N;
int answer = 1000000000;

void DFS(int counter, int pos) {
	if (counter == N / 2) {
		int startTeam = 0;
		int linkTeam = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (checker[i] == true && checker[j] == true) startTeam += point[i][j];
				if (checker[i] == false && checker[j] == false) linkTeam += point[i][j];
			}
		}
		answer = min(answer, abs(startTeam - linkTeam));
		return;
	}

	for (int i = pos; i < N; i++) {
		checker[i] = true;
		DFS(counter + 1, i + 1);
		checker[i] = false; // back-tracking
	}
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> point[i][j];
		}
	}
	DFS(0, 1);
	cout << answer;

	return 0;
}*/