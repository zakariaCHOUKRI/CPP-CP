#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

// int n, m;
// vector<int> dp, adj[100100];
// vector<int> visited;
// int answer = 0;
// int max1 = 0, max2 = 0;
// int t;
// int curr;


// int dfs(int u) {

//     visited[u] = 1;
//     curr = 0;
//     for (int x: adj[u]) {
//         cout << x <<  "-----" << endl;
//         if (!visited[x]) {
//             t = dfs(x);
//             max1 = 0;
//             max2 = 0;
//             if (t > max1) {
//                 max2 = max1;
//                 max1 = t;
//             }
//             else if (t > max2) {
//                 max2 = t;
//             }
//             answer = max(answer, max1 + max2 + 2);
//             curr = max(curr, max1);
//         }
//     }

//     return curr;


// }

int main() {

    sor3a

    cin >> n >> m;

    dp.resize(n, -1);
    visited.resize(n, 0);
    
    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        a--;
        b--;

        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    cout << dfs(0);


    return 0;
}