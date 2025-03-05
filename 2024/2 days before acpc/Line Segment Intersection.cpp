#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;

bool areThePointsOnTheSameSide(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    ll n1 = (y3-y1)*(x2-x1)-(x3-x1)*(y2-y1);
    ll n2 = (y4-y1)*(x2-x1)-(x4-x1)*(y2-y1);
    if (n1*n2 > 0) {
        return false;
    }
    return true;
}

int main() {

    sor3a

    ll t, x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (areThePointsOnTheSameSide(x1, y1, x2, y2, x3, y3, x4, y4) && areThePointsOnTheSameSide(x3, y3, x4, y4, x1, y1, x2, y2)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}