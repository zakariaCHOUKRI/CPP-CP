#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;

vector<int> adj[100005], adjt[100005], S; // S stores the finishing order
bool vis[100005];
int id[100005];

void dfs(int x, int pass, int num = 0) {

    vis[x] = true;
    vector<int> &adjlist = (pass == 1) ? adj[x] : adjt[x];
    for (int e : adjlist) {
        if (!vis[e]) {
            dfs(e, pass, num);
        }
    }

    S.push_back(x);
    if (pass == 2) id[x] = num;

}

int main() {

    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        a--,b--;
        adj[a].push_back(b);
        adjt[b].push_back(a);
    }

    for (int i=0; i<n; i++) {
        if (!vis[i]) {
            dfs(i, 1);
        }
    }

    memset(vis, false, sizeof vis);

    int components = 0;

    // we iterate backwards to reverse the finishing order
    for (int i=n-1; i>=0; i--) {
        if (!vis[S[i]]) {
            components++;
            dfs(S[i], 2, components);
        }
    }

    cout << components << "\n";

    for (int i=0; i<n; i++) {
        cout << id[i] << " ";
    }

    return 0;
}