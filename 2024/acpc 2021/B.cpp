#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, tmp;
unordered_map<ll, ll> mp;
ll ans;

ll nChoose2(ll n) {
    return (n*(n-1))/2;
}

int main() {

    // freopen("brimore.in","r",stdin);
    cin >> n;
    for (ll i=0; i<n; i++) {
        cin >> tmp;
        mp[tmp]++;
    }

    ans = 0;
    ll cnt = 0;
    for (auto elem: mp) {
        ans += cnt * nChoose2(elem.second);
        cnt += nChoose2(elem.second);
    }

    cout << ans << endl;

    return 0;
}