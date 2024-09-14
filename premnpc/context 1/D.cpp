#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a[17];
ll minVal, maxVal;
ll curSum;
int n;
void subsetSums( int l, int r, ll sum, int len)
{
    if (l > r) {
        if (len < n){
            curSum = sum * (len) * (ll) pow(-1, len);
            minVal = min(minVal, curSum);
            maxVal = max(maxVal, curSum);
        }
        
        return;
    }
 
    subsetSums(l + 1, r, sum + a[l], len+1);
 
    // Subset excluding arr[l]
    subsetSums(l+1,r,sum, len);
}

int main() {
    int t;
    cin >> t;
    while(t--){
        
        cin >> n;
        for (int i =0;i<n;++i){
            cin >> a[i];
            a[i] = a[i] * a[i] * a[i];
        }
        minVal = 10000000 , maxVal = -10000000;
        subsetSums(0, n-1, 0, 0);
        cout << minVal << " " << maxVal << "\n";
        
    }


    return 0;
}