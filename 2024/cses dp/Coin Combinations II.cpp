#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, x, c[105];
ll dp[1000005];

const ll mod = 1e9 + 7;

int main() {

    cin >> n >> x;
    for (int i=0; i<n; i++) {
        cin >> c[i];
    }

    dp[0] = 1;

    for (int i=0; i<n; i++) {
        for (int j=1; j<=x; j++) {
            if (j - c[i] >= 0) {
                dp[j] = (dp[j] + dp[j-c[i]]) % mod;
            }
        }
    }

    cout << dp[x] << endl;



    return 0;
}