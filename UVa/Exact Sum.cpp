// UVa 11057 - Exact Sum

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, a[10001], l, r;
    map<int, int> s;

    while (scanf("%d", &n) != EOF){

        for (int i=0; i<n; i++) scanf("%d", &a[i]);
        scanf("%d", &m);

        s.clear();
        for (int i=0; i<n; i++) s.insert(make_pair(a[i], m-a[i]));

        l = 0;
        r = m;

        for(auto i: s) {
            if (s.count(i.second) == 1 && abs(i.first - i.second) <= r - l) {
                r = max(i.first, i.second);
                l = m - r;
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", l, r);

    }
    return 0;
}