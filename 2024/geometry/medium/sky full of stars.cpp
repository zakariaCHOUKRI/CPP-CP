#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define sor3a ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {

    sor3a
    freopen("points.in","r",stdin);
    int t, n, l, r, x[1005], y[1005], ans, a[3], b[3];

    cin >> t;
    while (t--) {

        cin >> n >> l >> r;
        for (int i=0; i<n; i++) {
            cin >> x[i] >> y[i];
        }

        ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    int area = abs(x[i]*y[j] - x[j]*y[i] + x[j]*y[k] - x[k]*y[j] + x[k]*y[i] - x[i]*y[k]);
                    if (area >= l*2 && area <= r*2) {
                        a[0] = x[i] - x[j], b[0] = y[i] - y[j];
                        a[1] = x[j] - x[k], b[1] = y[j] - y[k];
                        a[2] = x[k] - x[i], b[2] = y[k] - y[i];
                        if (a[0]*a[1] + b[0]*b[1] == 0 || a[0]*a[2] + b[0]*b[2] == 0|| a[1]*a[2] + b[1]*b[2] == 0) {
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }


    return 0;
}