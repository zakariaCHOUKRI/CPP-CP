#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<int> adj[1010];
vector<int> vis;
int answer = 0;

void dfs(int u) {

    answer += 1;

    vis[u] = 1;

    for (auto x: adj[u]) {
        if (!vis[x]) {
            dfs(x);
        }
    }

}

int main() {

    sor3a

    cin >> n >> m;
    vis.resize(n, 0);

    

    int a,b;

    for (int i=0; i<m; i++) {
        
        cin >> a >> b;
        a--;
        b--;

        adj[b].push_back(a);
        adj[a].push_back(b);

    }

    if (m != n-1) {
        cout << "no";
        return 0;
    }

    dfs(0);

    if (answer == n) {
        cout << "yes";
    }
    else {
        cout << "no";
    }

    return 0;
}