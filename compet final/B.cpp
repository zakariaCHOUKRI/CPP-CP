#include <bits/stdc++.h>
#define sor3a ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

const int sz = 1e6 + 10;

vector<int> adj[sz];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i=0;i<m;i++) {
        int a, b, c;
        cin >> a >> b >> c;a--,b--;

        for (int k=0; k<n; k++) {
            adj[a + k*n].push_back(b + k*n);
        }
    }
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        solve();
    }





    return 0;
}