#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
vector<int> adj[100100];
vector<int> dp;
int answer = 0;

void dfs(int u, int v) {

    dp[u] = 0;

    vector<int> maxat;
    int ad = 0;

    for (int x: adj[u]) {

        if (x != v) {
            ad++;
            dfs(x, u);
            maxat.push_back(dp[x]);
            dp[u] = max(dp[u], dp[x]);
        }

    }

    sort(maxat.begin(), maxat.end(), greater<int>());

    if (ad >= 2) {
        answer = max(answer, 2+maxat[0]+maxat[1]);
        dp[u] += 1;
    }

    if (ad == 1) {
        answer = max(answer, 1+maxat[0]);
        dp[u] += 1;
    }

}

int main() {

    sor3a

    cin >> n >> m;

    dp.resize(n, -1);

    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);

    // for (int i: dp) {
    //     cout << i << " ";
    // }
    cout << answer;

    return 0;
}