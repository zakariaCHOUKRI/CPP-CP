#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

const int maxn = 40;
int C[maxn + 1][maxn + 1];
vector<long long> arr;

map<ii, bool> mp;

bool isSubsetSum(vector<long long>& nums, long long target) {
    int n = nums.size();

    map<long long, bool> dp;
    dp[0] = true; // Base case: zero sum is always possible

    for (int i = 0; i < n; ++i) {
        map<long long, bool> temp(dp);
        for (const auto& pair : temp) {
            long long newSum = pair.first + nums[i];
            if (newSum <= target) {
                dp[newSum] = true;
            }
        }
    }

    return dp.find(target) != dp.end() && dp[target];
}

void solve() {
    int n, s;
    cin >> n >> s;
    arr.resize(n);

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = C[a][b];
    }

    cout << (isSubsetSum(arr, s) == 1 ? "done" : "deal with it")  << endl;


}

int main(){

    int t;
    cin >> t;

    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }

    while (t--) {
        solve();
    }

    return 0;
}