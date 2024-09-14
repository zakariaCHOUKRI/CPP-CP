#include <bits/stdc++.h>

#define sor3a ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

ll n, p, elem;
vector<ll> pr;
map<pair<ll, ll>, ll> dp;


ll solve(ll i, ll j) {

    if (i == -1 or j == 0) {
        return 1;
    }

    if (j - pr[i] < 0){
        return 0;
    }
    if (dp.find({i, j}) != dp.end()) {
        return dp[{i, j}];
    }
    
    ll ans = solve(i-1, j) + solve(i-1, j-pr[i]);
    
    dp[{i, j}] = ans;
    return ans;
}

int main() {

    cin >> n;
    cin >> p;

    int idx = 0;
    for (int i=0; i<n; i++) {
        cin >> elem;
        if (elem <= p) {
            pr.push_back(elem);
            idx++;
        }
    }
    sort(pr.begin(), pr.end(), greater<int>());


    cout << solve(idx-1, p);


    return 0;
}