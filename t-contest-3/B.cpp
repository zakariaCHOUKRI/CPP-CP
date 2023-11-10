#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;

ll curr;
multiset<ll> ms;
set<ll> s;
ll dp[200];

void solve() {
    
    ms.clear();
    ll n, num;
    cin >> n;
    for (ll i=0; i<n; i++) {
        cin >> num;
        ms.insert(num);
    }

    ll ans = 0;

    for (ll elem: ms) {
        for (ll fib: s) {
            
            ll diff = fib - elem;
            
            if (diff < 0) {
                continue;
            }
            else {
                if (diff == elem) {
                    if (ms.count(diff) >= 2) {
                        ans += (ms.count(diff) - 1);
                        // cout << diff << " " << elem << "\n";
                        continue;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    ans += (ms.count(diff));
                    // cout << diff << " " << elem << "\n";
                }
            }
        }
    }

    // cout << ans << "\n";
    cout << ans/2 << "\n";

}

int main() {

    sor3a

    dp[0] = 1;
    s.insert(1);
    dp[1] = 1;
    curr = 1;
    while (dp[curr] < 1e10) {
        dp[curr+1] = dp[curr] + dp[curr-1];
        s.insert(dp[curr+1]);
        curr++;
    }

    // for (ll i: s) {
    //     cout << i << " ";
    // }
    
    ll t;
    cin >> t;
    while (t--) {
        solve();

    }

    return 0;
}