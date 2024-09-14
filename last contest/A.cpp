#include <bits/stdc++.h>

#define sor3a ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

ll mod = 1e9 + 7;
ll n;

ll puis(ll i) {
    ll ans = 1;
    for (ll j=0; j<i; j++) {
        ans *= 27;
        ans = ans % mod;
    }
    return ans;
}

int main() {

    cin >> n;

    vector<int> dp(n+1,0);
    dp[4] = 24;
    for (int i=5;i<=n;++i){
        dp[i] = dp[i-1] * (i-1) * 27;
        dp[i] = dp[i] % mod;
    }
    // ll res = 1;
    // res = res * n;
    // res = res % mod;
    // res = res * (n-1);
    // res = res % mod;
    // res = res * (n-2);
    // res = res % mod;
    // res = res * (n-3);
    // res = res % mod;

    // res *= puis(n-8);
    // res = res % mod;

    // ll sb4 = 531440;
    // res *= sb4;
    // res = res % mod;
    // cout << res;

    cout << dp[n]; 



    return 0;
}