#include <bits/stdc++.h>

using namespace std;

int main() {

    const int big = 1e9 + 123;
    unordered_map<int, int> mp;

    int n, a[200005], c[200005];

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i] >> c[i];
    }

    for (int i=0; i<n; i++) {
        mp[c[i]] = big;
    }

    for (int i=0; i<n; i++) {
        mp[c[i]] = min(mp[c[i]], a[i]);
    }

    int res = 0;
    for (auto elem: mp) {
        res = max(res, elem.second);
    }

    cout << res;

    return 0;
}