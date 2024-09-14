#include <bits/stdc++.h>

using namespace std;

int main() {

    string s, ss;
    set<string> st;
    cin >> s;
    int n = s.size();
    s = s + s;

    int i = 0;
    while (i<s.size()-n) {
        ss = s.substr(i, n);
        st.insert(ss);
        i++;
    }

    for (auto saaze: st) {
        cout << saaze;
        break;
    }


    return 0;
}