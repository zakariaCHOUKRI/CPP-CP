// UVa 11849 - CD

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, id, answer;
    set<int> cds;

    while (true) {

        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        answer = 0;
        cds.clear();

        while (n--) {
            scanf("%d", &id);
            cds.insert(id);
        }

        while (m--) {
            scanf("%d", &id);
            if (cds.count(id)) answer++;
        }

        printf("%d\n", answer);

    }




    return 0;
}