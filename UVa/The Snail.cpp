// UVa 00573 - The Snail

#include <bits/stdc++.h>
using namespace std;

int main() {

    int U, D, F, H=1;
    int j;
    float current;
    
    while (H) {
        
        scanf("%d %d %d %d", &H, &U, &D, &F);
        current = (float) 0;
        float rate = (F * U) / 100.0;
        
        j = 0;
        while (current >= 0 && current < H) {
            current += U;
            current -= j * rate;
            current -= D;
            j++;
        }
        
        if (current < 0) printf("failure on day %d\n", j);
        else if (current >= H) printf("success on day %d\n", j-1);
    }

    return 0;
}
