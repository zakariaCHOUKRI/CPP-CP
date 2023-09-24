#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
bool visited[100010];
vector<int> adj[100010];
queue<int> T;

void dfs(int start) {

    if (visited[start])
        return;

    visited[start] = 1;

    for (int vertex: adj[start])
        dfs(vertex);

    T.push(start);

}

int visiting[100005];

bool cycleDetector(int s){

    visiting[s] = 1;

    for (int i: adj[s]){

        if (visiting[i] == 0 && cycleDetector(i))
            return 1;

        else if (visiting[i]==1) return 1;
    }

    visiting[s] = 2;

    return 0;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        adj[b].push_back(a);
    }


    for (int i=1; i<=n; i++) {
        if (!visiting[i] && cycleDetector(i)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        if (!visited[i]) dfs(i);
    }

    while(!T.empty()){
        cout << T.front() << " ";
        T.pop();
    }


    return 0;
}