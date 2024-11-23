#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll dp[1000005];
int n;


int main() {

    cin >> n;

    dp[0] = 1;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=6; j++) {
            if (i >= j) {
                dp[i] = (dp[i] + dp[i-j])%mod;
            }
        }
    }

    cout << dp[n] << endl;


    return 0;
}