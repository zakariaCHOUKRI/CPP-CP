#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {

    ll a, b, c, x, y, g;
    cin >> a >> b >> c;
    c = -c;
    g = gcd(a, b, x, y);
    if (c % g) {
        cout << -1 << endl;
    } else {
        cout << (x*c)/g << " " << (y*c)/g << endl;
    }

}