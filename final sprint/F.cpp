#include <bits/stdc++.h>

using namespace std;

const int maxn = 41;
long long C[maxn + 1][maxn + 1];
long long n, arr[maxn];
long long s;
long long c[maxn], g[maxn];
unordered_map<long long, long long> mp;

vector<long long> subsetSums(long long idx) {

    vector<long long> res = {0};
         
    for (int i = 0; i <idx; i++) {
        const int v = res.size();
        for (int t = 0; t < v; t++) {
            res.push_back(res[t] + arr[i]);
            mp[s - (res[t] + arr[i])] = 1;
        }
    }

    return res;
}

int subsetSums2(int idx) {

    vector<long long> res = {0};
         
    for (int i = idx; i <n; i++) {
        const int v = res.size();
        for (int t = 0; t < v; t++) {
            res.push_back(res[t] + arr[i]);
            if (mp[res[t] + arr[i]])   {
                // cout << "----" << res[t] + arr[i] << endl;
                return 1;
            } 
        }
    }

    return 0;
}


int main() {

    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }

    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        cin >> n >> s;
        for (int i=0; i<n; i++) {
            cin >> c[i] >> g[i];
            arr[i] = C[c[i]][g[i]];
        }

        vector<long long> s1 = subsetSums(n/2);

        int res = subsetSums2(n/2);

        if (res)    cout << "done";
        else cout << "deal with it";
        cout << "\n";
        // for (int i=0; i<n; i++) {
        //     cout << arr[i] << " ";
        // }

        // cout << endl;
    }

    


    return 0;
}