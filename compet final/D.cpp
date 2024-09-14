#include <bits/stdc++.h>
#define sor3a ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long ll;
typedef pair<ll, pair<ll, ll>> iii;

#define f first
#define s second

ll n, a, b, c;
vector<iii> arr;
set<pair<ll, ll>> dp;

int main() {

    sor3a

    cin >> n;
    arr.resize(n);

    for (int i=0; i<n; i++) {
        cin >> a >> b >> c;
        arr[i].f = a;
        arr[i].s.f = b;
        arr[i].s.s = c;
    }

    sort(arr.begin(), arr.end());

    set<pair<ll, ll>>::iterator it;
    long long ans = 0;
    for (int i=0; i<n; i++) {
        it = dp.lower_bound({arr[i].f, 0});

        if (it == dp.begin()) {
            dp.insert({arr[i].s.f, max(ans, arr[i].s.s)});
            ans = max(ans, arr[i].s.s);
                    cout << i << " : " << ans << endl;

            continue;
        }
        
        it--;
        dp.insert({arr[i].s.f, max(ans, arr[i].s.s + (*it).s)});
        ans = max(ans, arr[i].s.s + (*it).s);
        cout << i << " : " << ans << endl;
    }

    // for (auto elem: dp) {
    //     cout << elem.f << " " << elem.s << endl;
    // }

    cout << -ans;





    return 0;
}