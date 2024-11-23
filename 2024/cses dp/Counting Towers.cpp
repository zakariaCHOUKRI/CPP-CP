#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll t, n, small, big, small_temp, big_temp;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while (t--) {

        cin >> n;

        small = 1;
        big = 1;

        for (ll i=1; i<n; i++) {
            small_temp = 4*small + big;
            big_temp = 2*big + small;

            small = small_temp % mod;
            big = big_temp % mod;
        }

        cout << (small + big) % mod << endl;

    }


    return 0;
}