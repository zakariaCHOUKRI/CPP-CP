#include <bits/stdc++.h>

#define sor3a ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

ll noDigits(ll n){
    return (ll)log10(n)+1;
}

ll findFirstDiv(ll idp, ll k){
    if (k == 1) return idp;
    else if (idp%k == 0)    return idp;

    return idp - idp%k + k;
}


int main() {
    ll l,r,k,tmp,idx,res=0;
    cin >> l >> r >> k;

    

    ll dig = noDigits(l);
    if (dig %2 == 0){
        idx = l;
    }
    else{
        idx = (ll)pow(10,dig);
    }

    idx = findFirstDiv(idx,k);
    

    while(idx <= r){
        if ((ll)pow(10,dig+1) <= r){
            res += ((ll)pow(10,dig+1) - idx)/(2*k);
        }
        else if(idx == r){
            res += 1;
        }
        else{
            res += (r - idx)/k;
        }
        dig += 2;
        
        idx = (ll)pow(10,dig);

        idx = findFirstDiv(idx,k);
    }

    cout << res;
    

    return 0;
}