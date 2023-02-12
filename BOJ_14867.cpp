#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
map<pair<int, int>, int> mp;
queue<pair<int, int>> q;

void enqueue(int x, int y, int num) {
	if (mp[{x, y}]) return;
	mp[{x, y}] = num + 1;
	q.push({ x, y });
}

int bfs(int x, int y) {
	mp[{x, y}] = 1;
	q.push({ x, y });
	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second;
		q.pop();
		enqueue(a, py, mp[{px, py}]);
		enqueue(px, b, mp[{px, py}]);
		enqueue(0, py, mp[{px, py}]);
		enqueue(px, 0, mp[{px, py}]);
		enqueue(min(px + py, a), max(0, px + py - a), mp[{px, py}]);
		enqueue(max(0, px + py - b), min(px + py, b), mp[{px, py}]);
	}
	if (mp[{c, d}]) return mp[{c, d}] - 1;
	else return -1;
}

int main() {
	cin >> a >> b >> c >> d;
	cout << bfs(0, 0) << "\n";
	return 0;
}