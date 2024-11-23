#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int LOG = 20;

int tree[200005], up[200005][LOG];
int n, q, x, k;

void build() {
    for (int i=2; i<=n; i++) {
        up[i][0] = tree[i];
    }

    for (int j=1; j<LOG; j++) {
        for (int i=2; i<=n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}

int kthAncestor(int node, int kth) {
    for (int j=0; j<=LOG; j++) {
        if (kth & (1 << j)) {
            node = up[node][j];
        }
    }
    return node;
}

int main() {

    cin >> n >> q;

    for (int i=2; i<=n; i++) {
        cin >> tree[i];
    }

    build();

    for (int i=0; i<q; i++) {
        cin >> x >> k;
        int res = kthAncestor(x, k);
        if (res) {
            cout << res << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}