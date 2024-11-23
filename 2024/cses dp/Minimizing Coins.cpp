#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, x, c[105], dp[1000005];
const ll infinity = INT_MAX;

int main() {

    cin >> n >> x;
    for (ll i=0; i<n; i++) {
        cin >> c[i];
    }

    fill(dp, dp + x + 1, infinity);

    dp[0] = 0;

    for (int i=0; i<n; i++) {
        for (int j=1; j<=x; j++) {
            if (j-c[i]>=0) {
                dp[j] = min(dp[j], 1+dp[j-c[i]]);
            }
        }
    }

    if (dp[x] == infinity) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }

    return 0;
}