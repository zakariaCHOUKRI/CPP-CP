#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;

ll t, l, diff, i, j, ii, jj;

void solve() {

    cin >> l;

    i = sqrt(l);
    j = i + 1;

    ii = i*i;
    jj = j*j;

    if (l == ii) {
        if (l%2 == 0) {
            cout << i << " " << 1 << "\n";
        }
        else {
            cout << 1 << " " << i << "\n";
        }
    }

    else {
        if (i%2 == 0) {
            if (abs(l - ii - 1) > abs(l - jj)) {
                cout << abs(l - jj - 1)<< " " << j << "\n";
            }
            else {
                cout << i + 1 << " " << abs(l - ii)<< "\n";
            }
        }
        else {
            if (abs(l - ii - 1) > abs(l - jj)) {
                cout << j << " " << abs(l - jj - 1) << "\n";
            }
            else {
                cout << abs(l - ii) << " " << i+1 << "\n";
            }
        }
    }


}

int main() {

    sor3a

    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}