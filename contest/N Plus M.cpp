#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;



int main() {

    sor3a

    // vector<bool> is_prime(100010, true);
    // is_prime[0] = is_prime[1] = false;
    // for (int i = 2; i * i <= 100010; i++) {
    //     if (is_prime[i]) {
    //         for (int j = i * i; j <= 100010; j += i)
    //             is_prime[j] = false;
    //     }
    // }

    


    int t, n, m;

    cin >> t;
    while (t--) {

        cin >> n;

        if (n == 2)
            cout << 2;
        else
            cout << 3;

        cout << "\n";
    }


}