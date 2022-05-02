#include <bits/stdc++.h>

using namespace std;
int n, m;
int counter = 0;
int arr[101][101];
bool visited[101] = { 0 };
queue<int> q;

void BFS(int v) {
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (arr[v][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = true;
                counter++;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = arr[y][x] = 1;
    }

    BFS(1);

    cout << counter << endl;
}



/* DFS Code
int map[101][101] = { 0 };
int visit[101] = { 0 };
int computer_num, ans = 0;

void dfs(int n) {
    ans++;
    visit[n] = 1;
    for (int i = 1; i <= computer_num; i++) {
        if (map[n][i] && !visit[i])
            dfs(i);
    }
}

int main() {
    int n;
    int x, y;
    scanf("%d %d", &computer_num, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        map[x][y] = map[y][x] = 1;
    }

    dfs(1);
    printf("%d\n", ans - 1);


}
*/