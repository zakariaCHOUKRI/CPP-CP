#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;

int main() {

    sor3a

    ll n, x1, y1, x2, y2, x3, y3;
    cin >> n;
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll weirdNumber = (y3-y1)*(x2-x1) - (x3-x1)*(y2-y1);
        if (weirdNumber == 0) cout << "TOUCH\n";
        else if (weirdNumber > 0) cout << "LEFT\n";
        else cout << "RIGHT\n";
    }

    return 0;
}