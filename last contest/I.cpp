#include <bits/stdc++.h>

#define sor3a ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

set<pair<int, int>> st;

int n, a, b, c, d;

int main() {

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> c >> d;
        for (int j=a; j<b; j++) {
            for (int k=c; k<d; k++) {
                st.insert({j, k});
            }
        }
    }

    cout << st.size();

    return 0;
}