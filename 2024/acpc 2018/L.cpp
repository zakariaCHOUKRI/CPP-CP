#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


using namespace std;
using ll = long long;



int main() {

    sor3a
    freopen("looking.in", "r", stdin);

    int t, n, k, ans;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        ans = 0;
        while (n--) {
            cin >> k;
            ans |= k;
        }
        cout << ans << endl;
    }


    return 0;
}