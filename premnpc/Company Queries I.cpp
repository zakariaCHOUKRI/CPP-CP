#include <bits/stdc++.h>
 
using namespace std;
 
const int LOG = 20;
 
int up[200005][LOG];
int parents[200005];
int x, k, n, q, ei;
 
void build() {
    for (int i=2; i<n+1; i++) {
        up[i][0] = parents[i];
    }
    for (int j=1; j<LOG; j++) {
        for (int i=1; i<n+1; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}
 
int kthAncestor(int x, int k) {
    for (int j=0; j<LOG; j++) {
        if (k & (1 << j)) {
            x = up[x][j];
        }
    }
 
    return x;
}
 
int main() {
 
    cin >> n >> q;
 
    for (int i=2; i<n+1; i++) {
        cin >> ei;
        parents[i] = ei;
    }
 
    build();
 
    for (int i=0; i<q; i++) {
        cin >> x >> k;
        int res = kthAncestor(x, k);
        if (res) {
            cout << res << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
 
 
    return 0;
}