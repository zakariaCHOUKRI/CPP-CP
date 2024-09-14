#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2)%mod;
    if (b % 2){
        long long aaa = (res*res)%mod;
        aaa = (aaa * a) % mod;
        return aaa;
    }
        
    else{
        long long aaa = (res*res)%mod;
        return aaa;
    }
        
}


int main() {

    long long n, a, b;
    cin >> n;

    while(n--) {
        cin >> a >> b;
        cout << binpow(a, b)<< endl;
    }

    return 0;
}