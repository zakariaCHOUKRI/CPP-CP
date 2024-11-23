#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool primes[1000005];
unordered_set<ll> tprimes;

bool is_t_prime(ll number) {
    return tprimes.find(number) != tprimes.end();
}

int main() {

    memset(primes, 1, sizeof primes);

    primes[0] = false;
    primes[1] = false;
    for (int i=2; i*i<1000005; i++) {
        if (primes[i]) {
            for (int j=i*i; j<1000005; j+=i) {
                primes[j] = false;
            }
        }
    }

    for (ll i=2; i<1000005; i++) {
        if (primes[i]) {
            tprimes.insert(i*i*1LL);
        }
    }

    ll n, no;
    cin >> n;
    while (n--) {
        cin >> no;
        if (is_t_prime(no)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}