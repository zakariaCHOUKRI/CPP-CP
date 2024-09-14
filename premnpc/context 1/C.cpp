#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k, m;
    double res = -1, tmp;
    double p[1005], r[1005];
    cin >> n >> k;
    for (int i=0; i<k; i++) {
        tmp = 0;
        cin >> m;
        // cout << "m:" <<m<<endl;
        for (int j=0; j<m; j++) {
            cin >> r[j];
        }
        for (int j=0; j<m; j++) {
            cin >> p[j];
        }
        for (int j=0; j<m; j++) {
            tmp += r[j] * p[j];
        }
        // cout << tmp << endl;
        res = max(res, n * tmp);
    }


    cout << setprecision(7) << res;

    return 0;
}