#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int LOG = 20;
const int maxN = 200005;

int up[maxN][LOG], in[maxN], out[maxN];
int n, q, a, b, timer, tmp;
vector<int> adj[maxN];

void dfs(int u, int v) {
    in[u] = ++timer;
    up[u][0] = v;
    for (int i=1; i<LOG; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (int w: adj[u]) {
        if (w != v) {
            dfs(w, u);
        }
    }
    out[u] = ++timer;
}

bool isAncestor(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
    if (isAncestor(u, v)) {
        return u;
    }
    if (isAncestor(v, u)) {
        return v;
    }
    for (int i=LOG-1; i>=0; i--) {
        if (!isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int main() {

    timer = 0;

    cin >> n >> q;
    for (int i=2; i<=n; i++) {
        cin >> tmp;
        adj[tmp].push_back(i);
        adj[i].push_back(tmp);
    }

    dfs(1, 1);

    for (int i=0; i<q; i++) {
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }

    return 0;
}