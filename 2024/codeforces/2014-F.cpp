#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

const int maxN = 2e5 + 5;
ll t, n, c, a[maxN], u, v, dp[maxN][2];
vi adj[maxN];

void dfs(int node, int parent) {

    dp[node][0] = 0;
    dp[node][1] = a[node];

    for (int neighbor: adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node);
            dp[node][0] += max(dp[neighbor][0], dp[neighbor][1]);
            dp[node][1] += max(dp[neighbor][0], dp[neighbor][1] - 2*c);
        }
    }
}

int main() {

    cin >> t;
    while (t--) {

        cin >> n >> c;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }

        for (int i=0; i<n-1; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0);

        cout << max(dp[1][0], dp[1][1]) << endl;

        for (int i=1; i<=n; i++) {
            adj[i].clear();
        }
    }
    return 0;
}