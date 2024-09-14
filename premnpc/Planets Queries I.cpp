#include <bits/stdc++.h>

using namespace std;

const int LOG = 30;

int n, q, ti, x, k;
int up[200005][LOG];
int parent[200005];

void build() {

    for (int v=0; v<n; v++) {
        up[v][0] = parent[v];
    }

    for (int j=1; j<LOG; j++) {
        for (int v=0; v<n; v++) {
            up[v][j] = up[up[v][j-1]][j-1];
        }
    }
}

int kthancestor(int u, int p) {

    for (int j=0; j<LOG; j++) {
        if (p & (1 << j)) {
            u = up[u][j];
        }
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for (int i=0; i<n; i++) {
        cin >> ti;
        ti--;
        parent[i] = ti;
    }

    build();

    for (int i=0; i<q; i++) {
        cin >> x >> k;
        x--;
        cout << kthancestor(x, k) + 1 << endl;
    }

    return 0;
}