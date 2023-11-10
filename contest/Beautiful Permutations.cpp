#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main() {

    sor3a

    int t, n;

    cin >> t;
    while (t--) {

        cin >> n;

        for (int i=1; i<=n; i+=2) {
            cout << i << " ";
        }

        for (int i=2; i<=n; i+=2) {
            cout << i << " ";
        }


    }


}