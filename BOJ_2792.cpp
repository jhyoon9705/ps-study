#include<bits/stdc++.h> 
using namespace std;

long long n, m, a[300002], ret = 1e18;
bool check(long long mid) {
    long long num = 0;
    for (int i = 0; i < m; i++) {
        num += a[i] / mid;
        if (a[i] % mid)num++;
    }
    return n >= num;
}
int main() {
    cin >> n >> m;
    long long lo = 1, hi = 0, mid;
    for (int i = 0; i < m; i++) cin >> a[i], hi = max(hi, a[i]);
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            ret = min(ret, mid);
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ret << "\n";
    return 0;
}