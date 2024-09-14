#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    unordered_map<char, int> mp;
    unordered_map<int, int> mp2;

    cin >> s;
    for (char c: s) {
        mp[c]++;
    }

    for (pair<char, int> p: mp) {
        mp2[p.second]++;
    }

    bool flag = 1;
    for (pair<int, int> p: mp2) {
        if (p.second != 2) {
            cout << "No";
            flag = 0;
            break;
        }
    }
    if (flag) {
        cout << "Yes";
    }


    return 0;
}