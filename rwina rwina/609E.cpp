#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+5;
const int mxL = 30;
pair<pair<int, int>, pair<int, int> > edge[mxN];
int par[mxN], height[mxN], level[mxN];
vector<pair<int, int> > adj[mxN];
int lca[mxN][mxL], heavy[mxN][mxL];
bool vis[mxN];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y)
        return false;
    if(height[x] > height[y])
        swap(x, y);
    par[y] = x, height[x] += height[y];
    return true;
}

void dfs(int u, int w, int p, int l = 0) {
    lca[u][0] = p;
    heavy[u][0] = w;
    level[u] = l;
    for(auto &v : adj[u]) {
        int a = v.first, b = v.second;
        if(a == p) continue;
        dfs(a, b, u, l+1);
    }
}

int LCA(int a, int b) {
    int result = 0;
    if(level[a] < level[b])
        swap(a, b);
    for(int i = mxL; i >= 0; i--) {
        if(level[a]-(1<<i) >= level[b]) {
            result = max(result, heavy[a][i]);
            a = lca[a][i];
        }
    }
    if(a == b)
        return result;
    for(int i = mxL-1; i >= 0; i--) {
        if(lca[a][i] != lca[b][i]) {
            result = max({result, heavy[a][i], heavy[b][i]});
            a = lca[a][i], b = lca[b][i];
        }
    }
    return max({result, heavy[a][0], heavy[b][0]});
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &edge[i].second.first, &edge[i].second.second, &edge[i].first.first);
        edge[i].first.second = i;
    }
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        height[i] = 1;
    }
    sort(edge, edge+m);
    long long ans = 0;
    int root = 0;
    for(int i = 0; i < m; i++) {
        int a = edge[i].second.first, b = edge[i].second.second;
        if(join(a, b)) {
            ans += edge[i].first.first;
            adj[edge[i].second.first].push_back({edge[i].second.second, edge[i].first.first});
            adj[edge[i].second.second].push_back({edge[i].second.first, edge[i].first.first});
            vis[i] = true;
        }
    }
    dfs(1, 0, 0);
    for(int j = 1; j < mxL; j++) {
        for(int i = 1; i <= n; i++) {
            lca[i][j] = lca[lca[i][j-1]][j-1];
            heavy[i][j] = max(heavy[i][j-1], heavy[lca[i][j-1]][j-1]);
        }
    }
    vector<long long> res(m);
    for(int i = 0; i < m; i++) {
        if(vis[i])
            res[edge[i].first.second] = ans;
        else {
            int a = edge[i].second.first, b = edge[i].second.second;
            int result = LCA(a, b);
            res[edge[i].first.second] = ans-result+edge[i].first.first;
        }
    }
    for(int i = 0; i < m; i++)
        printf("%lld\n", res[i]);
    return 0;
}