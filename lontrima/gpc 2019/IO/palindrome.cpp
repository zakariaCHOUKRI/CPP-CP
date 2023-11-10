#include <bits/stdc++.h>

using namespace std;

bool isPalindome(vector<int> s) {

    for (int i=0; i<s.size()/2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }
    return true;

}

vector<int> baseConvert(int n, int b) {
    
    vector<int> v;

    if (n==0) {
        v.push_back(0);
        return v;
    }

    while (n != 0) {
        v.push_back(n%b);
        n /= b;
    }
    return v;
}

int main() {

    int n, b;

    while (true) {

        cin >> n >> b;

        if (n==0 && b==0)
            break;

        bool a = isPalindome(baseConvert(n, b));
        if (a) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }





    }





    return 0;
}