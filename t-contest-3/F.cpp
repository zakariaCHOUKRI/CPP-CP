#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;

int n, k, d;
vector<ll> dp, dp2;
int mod = 1e9 + 7;

int main() {

    sor3a

    cin >> n >> k >> d;
    dp.resize(n+1, 0);
    dp2.resize(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            if(i-j >= 0) {
                dp[i] += dp[i-j];
                dp[i] = dp[i] % mod;
            }
        }
    }

    dp2[0] = 1;
    dp2[1] = 1;
    if (d == 1) {
        dp2[1] = 0;
        dp2[0] = 0;
    }
    for (int i=2; i<=n; i++) {
        for (int j=1; j<d; j++) {
            if(i-j >= 0) {
                dp2[i] += dp2[i-j];
                dp2[i] = dp2[i] % mod;
            }
        }
    }



    // for (int i: dp) {
    //     cout << i << " ";
    // } cout <<endl;
    // for (int i: dp2) {
    //     cout << i << " ";
    // } cout <<endl;


    cout << (dp[n] - dp2[n] + mod) % mod;


    return 0;
}