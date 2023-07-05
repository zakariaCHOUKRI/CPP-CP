// UVa 11172 - Relational Operators

#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    long long a, b;
    scanf("%d", &t);
    while (t--){
        scanf("%lld %lld", &a, &b);
        if (a > b) printf(">");
        else if (a < b) printf("<");
        else printf("=");
        if (t) printf("\n");
    }

    return 0;
}

