#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define sor3a ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll nChoose2(ll n) {
    return n * (n-1) / 2;
}

int main() {

    ll n, m;
    unordered_map<ll, ll> mp;

    freopen("brimore.in","r",stdin);
    cin >> n;
    while (n--) {
        cin >> m;
        mp[m]++;
    }

    ll cnt = 0, ans = 0;

    for (auto elem: mp) {
        ans += cnt * nChoose2(elem.second);
        cnt += nChoose2(elem.second);
    }

    cout << ans;

    return 0;
}