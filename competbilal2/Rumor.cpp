#include <bits/stdc++.h>

using namespace std;

long long n, m, c, x, y, minHere, ans;
long long price[100010], visited[100010];
vector<long long> graph[100010];

void dfs(long long start) {

    if (visited[start])
        return;

    if (minHere == -1 || minHere > price[start])
        minHere = price[start];

    visited[start] = true;

    for (long long i: graph[start])
        if (!visited[i])
            dfs(i);

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (long long i=1; i<=n; i++) {
        cin >> c;
        price[i] = c;
    }

    for (long long i=0; i<m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    ans = 0;
    for (long long i=1; i<=n; i++) {
        if (!visited[i]) {
            minHere = -1;
            dfs(i);
            ans += minHere;
        }
    }

    cout << ans;

    return 0;
}