#include <bits/stdc++.h>

using namespace std;

int main() {

    string s, t;
    unordered_set<char> st;

    cin >> s;
    cin >> t;

    for (char c: s) {
        st.insert(toupper(c));
    }

    if (st.find(t[0]) != st.end() && st.find(t[1]) != st.end() && (st.find(t[2]) != st.end() || t[2] == 'X' )) {
        cout << "Yes";
    } else {
        cout << "No";
    }


    return 0;
}