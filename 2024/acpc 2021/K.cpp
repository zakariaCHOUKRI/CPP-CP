#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int dp[5005][5005][2];
int n, arr[5005];
const int mod = 1e9 + 7;
 
int solve(int idx, int remainingSumForValid, bool takeThisOneAsLargest) { // we use the rule Ri < sum(Rj), j != i
 
    if (idx == n) {
        return (remainingSumForValid == 0) && takeThisOneAsLargest;
    }
 
    if (dp[idx][remainingSumForValid][takeThisOneAsLargest] != -1) {
        return dp[idx][remainingSumForValid][takeThisOneAsLargest];
    }
 
    int res = 0;
 
    // dont consider this side
    res = (res + solve(idx + 1, remainingSumForValid, takeThisOneAsLargest)) % mod;
 
    // consider this side
    if (!takeThisOneAsLargest) { // let's use it as the largest side
        res = (res + solve(idx + 1, arr[idx] + 1, true)) % mod;
    } else {
        res = (res + solve(idx + 1, max(0, remainingSumForValid - arr[idx]), true)) % mod;
    }
 
    return dp[idx][remainingSumForValid][takeThisOneAsLargest] = res;
}
 
int main() {
    freopen("polygon.in","r",stdin);
 
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
 
    sort(arr, arr+n, std::greater<int>());
    memset(dp, -1, sizeof dp);
 
    cout << solve(0, 0, false);
 
    return 0;
}