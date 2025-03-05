#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;

int main() {

    sor3a

    ll n, x[1001], y[10001];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    x[n] = x[0];
    y[n] = y[0];

    ll res = 0;
    for (int i=0; i<n; i++) {
        res += (x[i] * y[i+1]) - (x[i+1] * y[i]);
    }

    cout << abs(res) << endl;

    return 0;
}