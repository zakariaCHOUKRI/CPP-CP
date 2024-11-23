#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, x, y, arr[100005];


int main() {

    // freopen("apple.in","r",stdin);
    cin >> n;
    cin >> x >> y;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int small = 0;
    int medium = 0;
    int big = 0;

    for (int i=0; i<n; i++) {
        if (arr[i] <= x) {
            small++;
        } else if (arr[i] <= y) {
            medium++;
        } else {
            big++;
        }
    }

    cout << small << " " << medium << " " << big << endl;


    return 0;
}