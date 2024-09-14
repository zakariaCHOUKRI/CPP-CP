#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    for (int i=0; i<s.size(); i++) {
        if (s[i] != s[s.size()-1-i]) {
            return false;
        }
    }
    return true;
}

string convert(int n, int b) {
    string res;
    vector<int> resv;

    if (n == 0) {
        return "0";
    }

    while (n) {
        resv.push_back(n%b);
        n /= b;
    }

    for (int i=resv.size()-1; i>=0; i--) {
        res += ('0' + resv[i]);
    }

    return res;

}

int main() {

    int n, b;

    while (true) {
        cin >> n >> b;
        if (n == 0 && b == 0)
            break;

    if (isPalindrome(convert(n, b)))
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    }


    return 0;
}