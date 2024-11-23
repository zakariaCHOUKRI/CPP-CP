#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, x, h[1005], s[1005], dp[100005];

int main() {

    cin >> n >> x;
    for (int i=0; i<n; i++)
        cin >> h[i];
    for (int i=0; i<n; i++)
        cin >> s[i];

    for (int i=0; i<n; i++) {
        for (int j=x; j>=h[i]; j--) {
            dp[j] = max(dp[j], s[i] + dp[j - h[i]]);
        }
    }

    cout << dp[x] << endl;

    return 0;
}