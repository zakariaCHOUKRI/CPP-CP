#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100010];
int n, m, a, b;
int dist[100010], parent[100010];
bool visited[100010];

bool bfs() {

    queue<int> q;
    int node;

    dist[1] = 1;
    visited[1] = true;
    q.push(1);

    while(!q.empty()) {

        node = q.front();
        q.pop();

        if (node == n) return true;

        for (int u: adj[node]) {
            if (visited[u] == false) {
                dist[u] = dist[node] + 1;
                visited[u] = true;
                parent[u] = node;
                q.push(u);
            }
        }
    }

    return false;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (bfs()) {

        cout << dist[n] << "\n";

        int path = n;
        vector<int> result;

        while (path != 0) {
            result.push_back(path);
            path = parent[path];
        }

        for (int i=result.size()-1; i>=0; i--)
            cout << result[i] << " ";

    }
    
    else {
        cout << "IMPOSSIBLE";
    }




    return 0;
}