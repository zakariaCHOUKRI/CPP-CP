#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n;
vector<int> dp;


int main() {

    sor3a

    cin >> n;
    dp.resize(n+1, 1e9);

    dp[0] = 0;

    for (int i=1; i<=n; i++) {
        int a = i;
        while (a != 0) {
            dp[i] = min(dp[i], dp[i-a%10]+1);
            a /= 10;
        }
    }

    cout << dp[n];

    return 0;
}