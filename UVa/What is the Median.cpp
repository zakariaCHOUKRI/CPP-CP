// UVa 10107 - What is the Median?

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll x;
    vector<ll> vect;
    int idx;

    while (scanf("%lld", &x) != EOF) {

        vect.push_back(x);
        sort(vect.begin(), vect.end());

        if (vect.size() % 2) printf("%lld\n", vect[vect.size()/2]);
        else {

            idx = vect.size() / 2;
            printf("%lld\n", (vect[idx] + vect[idx-1])/2);

        }
    }

    return 0;
}