#include <bits/stdc++.h>
#define sor3a ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int n;
unordered_map<int, int> mp;
int s, m, l;

int solve(int idx) {
    

    if (idx<=0) {
        return 0;
    }

    if (mp.find(idx) != mp.end()) {
        return mp[idx];
    }

    int ans = 0;
    ans = min(solve(idx-6) + s, min(solve(idx-8) + m, solve(idx-12) + l));
    mp[idx] = ans;
    return ans;

}

int main() {

    cin >> n;
    cin >> s >> m >> l;
    cout << solve(n);





    return 0;
}