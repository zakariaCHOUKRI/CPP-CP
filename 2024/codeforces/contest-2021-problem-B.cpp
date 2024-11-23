#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    int t, n, x, tmp, mex;
    cin >> t;
    while (t--) {
        unordered_map<int, int> arr;
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            arr[tmp] += (tmp < n);
        }
        for (mex=0; mex<n && arr[mex]; mex++) {
            arr[mex + x] += arr[mex] - 1;
        }
        cout << mex << endl;
    }

    return 0;
}