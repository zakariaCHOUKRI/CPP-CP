#include <bits/stdc++.h>

#define sor3a ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;


int main() {

    ll n, d, p, h, arr[200005];

    cin >> n >> d >> p;
    for (ll i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n, greater<ll>());

    ll res = 0;
    for (int i=0;i<n;i += d){
        ll sum = 0;
        for (int j=0;j<d;++j){
            if (i+j<n){
                sum += arr[i+j];
                

            }
        }

        if (sum >= p){
            res += p;
        }
        else{
            for (int idx=i;idx<n;++idx){
                res += arr[idx];
                // cout << "eeee" << endl;
            }
            break;
        }
    }

    cout << res << endl;
    
    // ll idx = 0;
    // ll sum = 0;
    // ll res = 0;
    // while (idx < n) {
    //     sum = 0;
    //     ll j;
    //     for (j=idx; j<idx+d && j<n; j++) {
    //         sum += arr[j];
    //     }
        
    //     if (sum >= p){
    //         res += p;
            
    //     }
    //     else{
    //         break;
    //     }
    //     idx = j;
        
    // }

    // for (ll i=idx;i<n;++i){
    //     res += arr[i];
    // }

    // cout << res;

    return 0;
}