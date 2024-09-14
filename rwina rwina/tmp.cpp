#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n, q;
    long long arr[200001];
    long long a, b, tmp;

    cin >> n >> q;
    for (long long i=0; i<n; i++) {
        cin >> tmp;
        if (i > 0) {
            arr[i] = arr[i-1] + tmp;
        } else {
            arr[i] = tmp;
        }
    }

    while (q--) {
        cin >> a >> b;
        if (a > 1) {
            cout << arr[b-1] - arr[a-2] << endl;
        }
        else {
            cout << arr[b-1] << endl;
        }
    }

    return 0;
}