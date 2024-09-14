#include <bits/stdc++.h>

using namespace std;

const int LOG = 20;

int n, q, a, b, m, ei;
vector<int> adj[10005];
int depth[10005];
int up[10005][LOG];

void dfs(int u, int par) {

    up[u][0] = par;
    for (int j=1; j<LOG; j++) {
        up[u][j] = up[up[u][j-1]][j-1];
    }

    for (int x: adj[u]) {
        if (x != par) {
            depth[x] = depth[u] + 1;
            dfs(x, u);
        }
    }
}

int lca(int u, int v) {

    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    int k = depth[u] - depth[v];
    for (int j=LOG-1; j>=0; j--) {
        if (k & (1 << j)) {
            u = up[u][j];
        }
    }

    if (u == v) {
        return u;
    }

    for (int j=LOG-1; j>=0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

int main() {

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> m;
        adj[i].clear();
        for (int j=0; j<m; j++) {
            cin >> ei;
            adj[i].push_back(ei);
        }
    }

    dfs(0, -1);

    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }



    return 0;
}