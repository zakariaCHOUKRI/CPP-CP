#include <bits/stdc++.h>

using namespace std;

int main() {

    map<char,int> m;
    string s;
    cin >> s;
    int ans = 0;
    char ansc;
    int flag = 0;
    for (char c : s){
        m[c]++;
        if (ans < m[c]){
                ans = m[c];
        }
            
        }
        
    for (auto elem : m){
        if (elem.second == ans){
        cout << elem.first << endl;
        break;
        }
    }
    // cout << ans;


    


    return 0;
}