#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main() {

    sor3a

    int n, m, k, a[200100], b[200100], ans;

    cin >> n >> m >> k;

    for (int i=0; i<n; i++)
        cin >> a[i];

    for (int i=0; i<m; i++)
        cin >> b[i];

    int i, j, count;
    i = j = count = 0;
    while (i < n && j < m) {

        if (abs(a[i] - b[j]) <= k) {
            count++;
            i++;
            j++;
        }
        else if ()


    }

    return 0;
}