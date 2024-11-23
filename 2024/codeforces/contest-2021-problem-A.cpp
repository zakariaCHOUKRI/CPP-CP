#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    int n, sz;
    ll ai;

    cin >> n;
    while (n--) {

        priority_queue<ll, vector<ll>, greater<ll>> s;

        cin >> sz;
        while (sz--) {
            cin >> ai;
            s.push(ai);
        }

        while (s.size() > 1) {
            ll a = s.top(); s.pop();
            ll b = s.top(); s.pop();
            s.push((a + b)/2);
        }

        cout << s.top() << endl;
    }

    return 0;
}