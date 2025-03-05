#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;

int main() {

    sor3a

    ll t, n, k, a, arr[365];
    set<ll> s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        s.clear();
        for (int i=0; i<n; i++) {
            cin >> a;
            s.insert(a);
        }
        int i = 0;
        for (ll x: s) {
            arr[i] = x;
            i++;
        }
        arr[i] = *s.begin() + 360;
        ll gap, res = 2024;
        for (int j=1; j<=i; j++) {
            gap = arr[j] - arr[j-1];
            res = min(res, 360-gap);
        }

        cout << (res+k-1)/k << endl;
    }

    return 0;
}