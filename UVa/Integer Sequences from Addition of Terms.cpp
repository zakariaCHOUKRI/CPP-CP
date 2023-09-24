// UVa 927 - Integer Sequences from Addition of Terms

#include <bits/stdc++.h>

using namespace std;

int main(){

    int c, i, cj[22], d, k, n, prev;
    long long result;

    scanf("%d", &c);
    while (c--){

        scanf("%d", &i);
        for (int j=0; j<i+1; j++) scanf("%d", &cj[j]);
        scanf("%d", &d);
        scanf("%d", &k);

        n = 1;
        prev = n*d;
        while (prev < k){
            n++;
            prev += n*d;
        }

        result = 0;
        for (int j=0; j<i+1; j++) result += cj[j] * pow(n, j);
        printf("%lld\n", result);

    }
    return 0;
}