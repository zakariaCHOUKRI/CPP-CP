#include <bits/stdc++.h>
#define sor3a ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef pair<int, pair<int, int>> iii;

int n, m, u, v, b, c;
const int sz = 2e15 + 10;
int dp1[sz], dp2[sz], dp[sz];
vector<iii> adj[sz];

void solve(int idx) {

    if (dp[idx] != -1) {
        return dp[idx];
    }

    int ans = 0;
    for (auto elem: adj[idx]) {
        solve(elem.first);
    }

}

int main() {

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> u >> v >> b >> c;u--,v--;
        adj[v].push_back({u, {b, c}});
    }





    return 0;
}