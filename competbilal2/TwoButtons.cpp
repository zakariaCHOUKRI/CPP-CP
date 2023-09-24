#include <bits/stdc++.h>

using namespace std;

int n, m, u;
bool visited[100000];
int dist[100000];

bool bfs() {

    queue<int> q;
    int node;

    dist[n] = 0;
    visited[n] = true;
    q.push(n);

    for (int i=0; i<n; i++) {
        dist[i] = n-i;
    }

    while(!q.empty()) {

        node = q.front();
        q.pop();

        if (node == m) return true;
        
        u = node-1;
        if (visited[u] == false && u>=0) {
            dist[u] = dist[node] + 1;
            visited[u] = true;
            q.push(u);
        }

        u = node*2;
        if (visited[u] == false && u<=20000) {
            dist[u] = dist[node] + 1;
            visited[u] = true;
            q.push(u);
        }
    }

    return false;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    // n = 14;
    // m = 1;

    // if (n > m)
    //     cout << n-m;
    // else if (n==m)
    //     cout << 0;
    // else {
        bfs();
        cout << dist[m];
    // }

    return 0;
}