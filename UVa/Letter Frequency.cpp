// UVa 11577 - Letter Frequency

#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, max;
    string s;
    map<char, int> m;

    scanf("%d", &t);
    cin.ignore();
    while(t--){

        max = 0;
        m['a'] = m['b'] = m['c'] = m['d'] = m['e'] = m['f'] = m['g'] = m['h'] = m['i'] = 0;
        m['j'] = m['k'] = m['l'] = m['m'] = m['n'] = m['o'] = m['p'] = m['q'] = m['r'] = 0;
        m['s'] = m['t'] = m['u'] = m['v'] = m['w'] = m['x'] = m['y'] = m['z'] = 0;

        getline(cin, s);
        
        for (int i=0; i<s.size(); i++) {
            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);

                m[s[i]] += 1;

                if (m[s[i]] > max) max = m[s[i]];
            }
        }

        for(auto& p: m) if (p.second == max) printf("%c", p.first);
        printf("\n");
    }


    return 0;
}