#include <bits/stdc++.h>

using namespace std;

const int LOG = 20;

int n, q, ei, a, b;
vector<int> adj[200005];
int depth[200005];
int up[200005][LOG];

void dfs(int u, int par) {

    up[u][0] = par;
    for (int j=1; j<LOG; j++) {
        up[u][j] = up[up[u][j-1]][j-1];
    }

    for (int v: adj[u]) {
        if (v != par) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int a, int b) {

    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    int k = depth[a] - depth[b];
    for (int j=LOG-1; j>=0; j--) {
        if (k & (1 << j)) {
            a = up[a][j];
        }
    }

    if (a == b) {
        return a;
    }

    for (int j=LOG-1; j>=0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0];
}

int main() {

    cin >> n >> q;

    for (int i=2; i<n+1; i++) {
        cin >> ei;
        adj[ei].push_back(i);
    }

    dfs(1, -1);

    for (int i=0; i<q; i++) {
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }

    return 0;
}