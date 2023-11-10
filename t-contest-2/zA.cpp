#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;

int t, n;

bool isValid(ll middle) {
    return middle * middle >= n;
}

void solve() {
    cin >> n;

    ll left = 0;
    ll right = 1e8;
    ll answer = -1;

    while (left <= right) {
        ll mid = left + (right - left)/2;
        if (isValid(mid)) {
            answer = mid;
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }

    cout << answer << "\n";
}

int main() {

    sor3a
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}