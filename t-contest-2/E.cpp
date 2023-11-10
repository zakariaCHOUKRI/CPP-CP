#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n, A, B;
int t, a, b, c;
vector<int> adj[200100];
vector<int> vis, cyc;
vector<int> stc;
bool cnt = true;

void dfs1(int u, int v) {

    if (!cnt) {
        return;
    }

    if (vis[u] == 1) {
        cnt = false;
        cyc[u] = 1;
        while (stc.size() > 0 && stc[stc.size()-1] != u) {
            cyc[stc[stc.size()-1]] = 1;
            stc.pop_back();
        }
    }

    vis[u] = 1;

    stc.push_back(u);

    for (int x: adj[u]) {
        if (x!=v) {
            dfs1(x, u);
        }
    }


    stc.pop_back();
}

bool cnt2 = true;
int answer = 1e9;
void dfs2(int u, int v) {
    if (cyc[u] == 1) {
        cnt2 = false;
    }

    if (!cnt2) {
        return;
    }

    vis[u] = 1;

    for (int x: adj[u]) {
        if (x!=v) {
            dfs1(x, u);
        }
    }

}

void solve() {

    cin >> n >> A >> B;
    vis.resize(n, 0);
    cyc.resize(n, 0);

    for (int i=0; i<n; i++) {
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(0, -1);
    dfs2(A, -1);

    for (int i=0; i<cyc.size(); i++) {
        cout << cyc[i] << " ";
    }




    for (int i=0; i<n; i++) {
        adj[i].clear();
    }

}

int main() {

    sor3a

    cin >> t;
    while (t--) {

        solve();


    }

    return 0;
}