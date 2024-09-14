#include <bits/stdc++.h>

using namespace std;

constexpr long long BIG = 1e18;  // We can't use LLONG_MAX because of overflow

int main() {

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> min_dist(n, vector<long long>(n, BIG));
    for (int i = 0; i < m; i++) {
        int a, b;
        int c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (c < min_dist[a][b]) { min_dist[a][b] = min_dist[b][a] = c; }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long new_dist = min_dist[i][k] + min_dist[k][j];
                if (new_dist < min_dist[i][j]) {
                    min_dist[i][j] = min_dist[j][i] = new_dist;
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        // Check if the two nodes are the same or can't reach each other
        if (a == b) {
            min_dist[a][b] = 0;
        } else if (min_dist[a][b] == BIG) {
            min_dist[a][b] = -1;
        }

        cout << min_dist[a][b] << '\n';
    }

    return 0;
}