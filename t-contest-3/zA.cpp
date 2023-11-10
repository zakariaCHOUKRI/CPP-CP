#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;

ll n, k, q, x, y, ans;

ll findParent(ll x) {
    return (x-1)/k;
}

void solve() {

    cin >> x >> y;
    if (k == 1) {
        cout << abs(x-y) << "\n";
        return;
    }
    
    x--;
    y--;

    ans = 0;
    while (x != y) {
        if (x>y) {
            x = findParent(x);
        }
        else {
            y = findParent(y);
        }
        ans++;
    }

    cout << ans << "\n";
}



int main() {

    sor3a

    cin >> n >> k >> q;

    for (ll i=0; i<q; i++) {
        solve();
    }

    return 0;
}