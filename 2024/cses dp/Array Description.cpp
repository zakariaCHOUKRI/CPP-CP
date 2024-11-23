#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int n, m, arr[100005], dp[100005][105], res;

int main() {

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int k=1; k<=m; k++) {
        if (arr[0] == 0 || arr[0] == k) {
            dp[0][k] = 1;
        } else {
            dp[0][k] = 0;
        }
    }

    for (int i=1; i<n; i++) {
        for (int k=1; k<=m; k++) {
            if (arr[i] == 0 || arr[i] == k){
                if (k - 1 >= 1)
                    dp[i][k] = (dp[i][k] + dp[i-1][k-1]) % mod;
                if (k + 1 <= m)
                    dp[i][k] = (dp[i][k] + dp[i-1][k+1]) % mod;

                dp[i][k] = (dp[i][k] + dp[i-1][k]) % mod;
            }
        }
    }

    res = 0;
    for (int i=1; i<=m; i++) {
        res = (res + dp[n-1][i]) % mod;
    }

    cout << res << endl;

    return 0;
}