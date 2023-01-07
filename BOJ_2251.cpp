#include <bits/stdc++.h>

using namespace std;

int A, B, C;

vector<int> result;
queue<pair<pair<int, int>, int>> q;
bool visited[201][201][201];

void BFS(void) {
	q.push({ {0, 0}, C });

	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (visited[a][b][c] == true) continue;

		visited[a][b][c] = true;

		if (a == 0) result.push_back(c);

		// a -> b
		if (a + b > B) q.push({ {a + b - B, B}, c });
		else q.push({ {0, a + b}, c });

		// a -> c
		if (a + c > C) q.push({ {a + b - C, b}, C });
		else q.push({ {0, b}, a + c });

		// b -> a
		if (b + a > A) q.push({ {A, b + a - A}, c });
		else q.push({ {b + a, 0}, c });

		// b -> c
		if (b + c > C) q.push({ {a, b + c - C}, C });
		else q.push({ {a, 0}, b + c });

		// c -> a
		if (c + a > A) q.push({ {A, b}, c + a - A });
		else q.push({ { c + a, b }, 0 });

		// c -> b
		if (c + b > B) q.push({ {a, B}, c + b - B });
		else q.push({ {a, c + b}, 0 });
	}
}

int main() {
	cin >> A >> B >> C;

	BFS();
	sort(result.begin(), result.end());
	
	for (int i = 0; i < (int)result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}