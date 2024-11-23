#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;


int main() {

    sor3a

    freopen("coffee.in", "r", stdin);

    int t, c, p, s, m, l, total;
    string n, x, y, z;
    

    cin >> t;
    while (t--) {
        unordered_map<string, vector<int>> prices;
        unordered_map<string, int> people;

        cin >> c >> p;
        for (int i=0; i<c; i++) {
            cin >> n >> s >> m >> l;
            prices[n] = {s, m, l};
        }

        for (int i=0; i<p; i++) {
            cin >> x >> y >> z;
            
            total = 100/p;
            if (y[0] == 's') {
                total += prices[z][0];
            } else if (y[0] == 'm') {
                total += prices[z][1];
            } else {
                total += prices[z][2];
            }

            if (total % 5 == 1) {
                total--;
            } else if (total % 5 == 4) {
                total++;
            }

            cout << x << " " << total << "\n";
        }

    }


    return 0;
}