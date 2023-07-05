// UVa 12577 - Hajj-e-Akbar

#include <bits/stdc++.h>
using namespace std;

char name[10];

int main() {

    int i = 0;
    while (++i) {
        scanf("%s", &name);
        if (name[0] == 'H') printf("Case %d: Hajj-e-Akbar\n", i);
        else if (name[0] == 'U') printf("Case %d: Hajj-e-Asghar\n", i);
        else break;
    }

    return 0;
}
