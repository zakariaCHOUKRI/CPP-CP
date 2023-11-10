#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    string s, m, tmp;
    deque<string> d;

    cin >> t;

    for (int testCase=1; testCase<=t; testCase++) {

        d.clear();
        cout << testCase << ". ";

        cin >> s;

        tmp = "";
        for (int i=0; i<s.size(); i++) {

            if (isdigit(s[i])) {
                
                if (s[i]%2 == 0) {
                    d.push_front(tmp);
                }
                else {
                    d.push_back(tmp);
                }

                tmp = "";

            }
            else {
                tmp += s[i];
            }


        }

        for (string str: d) {
            cout << str;
        }
        cout << "\n";



    }




    return 0;
}