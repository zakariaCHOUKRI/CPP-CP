#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, q, xi, mi, a;
    vector<int> x, m;
    vector<int>::iterator it;

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &xi);
        x.push_back(xi);
    }

    scanf("%d", &q);
    for (int i=0; i<q; i++) {
        scanf("%d", &mi);
        m.push_back(mi);
    }

    sort(x.begin(), x.end());

    // for (int i=0; i<n; i++)
    //     printf("%d ", x[i]);
    // printf("\n");

    for (int i=0; i<q; i++) {
        
        if (m[i] < x[0])
            printf("0\n");

        else {
            it = upper_bound(x.begin(), x.end(), m[i]);
            if (it == x.end()) 
                printf("%d\n", n);
            else {
                a = 0;
                //printf("%d\n", *it);
                if (*it == m[i]) {
                    while (it != x.begin() - 1) {
                        a++;
                        it--;
                    }
                }
                else {
                    while (it != x.begin()) {
                        a++;
                        it--;
                    }
                }
                printf("%d\n", a);
            }
        }
    }


    return 0;
}