#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, a, m, q, count;
    vector<int> v;
    vector<int>::iterator it;

    scanf("%d", &n);
    v.push_back(1);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a);
        v.push_back(a + v[i-1]);
    }

    // for (int i=0; i<=n; i++)
    //     printf("%d ", v[i]);
    // printf("\n");

    scanf("%d", &m);
    while (m--) {

        scanf("%d", &q);
        it = upper_bound(v.begin(), v.end(), q);
        count = 0;
        while (it != v.begin()) {
            count++;
            it--;
        }
        printf("%d\n", count);

    }

    return 0;
}