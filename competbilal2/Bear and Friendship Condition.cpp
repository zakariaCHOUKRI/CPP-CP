#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, numberOfNeighbors;
vector<int> graph[150050];
bool seen[150050];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // for (int i=1; i<=n; i++) {
    //     cout << i << ":";
    //     for (int neighbor: graph[i])
    //         cout << " " << neighbor;
    //     cout << "\n";
    // }

    bool yes = true;

    for (int i=1; i<=n; i++) {
        if (!seen[i]) {
            numberOfNeighbors = graph[i].size();
            for (int neighbor: graph[i]) {
                seen[i] = true;
                if (graph[neighbor].size() != numberOfNeighbors)
                    yes = false;
            }
        }
    }

    if (yes) cout << "YES";
    else cout << "NO";

    return 0;
}