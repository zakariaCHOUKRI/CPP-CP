#include <bits/stdc++.h>

#define sor3a ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
#define ii pair<int,int>
#define iii pair<int,ii>

using namespace std;

map<int, iii> mp;

bool verify(int i) {
    return (mp[i].first != mp[i].second.first) && (mp[i].first != mp[i].second.second) && (mp[i].second.first != mp[i].second.second);
}

int main() {

    int m;
    cin >> m;

    string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;

    for (int i=0; i<m; i++) {
        int ra9m1 = s1[i] - '0';
        if (mp.find(ra9m1) != mp.end()) {
            mp[ra9m1].first++;
            if (verify(ra9m1)) {
                cout << i;
                return 0;
            }
        } else {
            mp[ra9m1] = {1, {0, 0}};
        }

        int ra9m2 = s2[i] - '0';
        if (mp.find(ra9m2) != mp.end()) {
            mp[ra9m2].second.first++;
            if (verify(ra9m2)) {
                cout << i;
                return 0;
            }
        } else {
            mp[ra9m2] = {0, {1, 0}};
        }

        int ra9m3 = s3[i] - '0';
        if (mp.find(ra9m3) != mp.end()) {
            mp[ra9m3].second.second++;
            if (verify(ra9m3)) {
                cout << i;
                return 0;
            }
        } else {
            mp[ra9m3] = {0, {0, 1}};
        }

        
    }

    cout << -1;

    return 0;
}