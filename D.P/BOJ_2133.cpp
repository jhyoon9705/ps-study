// dp[n] = dp[n-2] x 3 + dp[n-4] x 2 + dp[n-6] x 2 + ... + 2
#include <bits/stdc++.h>

using namespace std;

int dp[31] = { 0 };

int main() {
    int n;
    int dp[31];

    cin >> n;

    dp[0] = 1;
    dp[2] = 3;

    if (n % 2 == 1) dp[n] = 0;
    else {
        for (int i = 4; i <= n; i += 2) {
            dp[i] = 3 * dp[i - 2];
            for (int j = 4; j <= i; j += 2) {
                dp[i] += 2 * dp[i - j];
            }
        }
    }
    cout << dp[n];
    return 0;
}