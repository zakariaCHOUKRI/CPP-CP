// https://cses.fi/problemset/task/1092/

#include <cstdio>

int main() {
    int n, high, low = 1;
    scanf("%d", &n);
    high = n;

    if (n%4 == 1 || n%4 == 2) printf("NO");
    
    else if (n%4 == 3){
        printf("YES\n");
        
        printf("%d\n", n/2);
        printf("%d ", high);
        high--;
        for (int i=0; i < (n-1)/4; i++) {
            printf("%d ", low);
            printf("%d ", high);
            low++;
            high--;
        }

        printf("\n%d\n", n/2 + 1);
        for (int i=0; i < (n+1)/4; i++) {
            printf("%d ", low);
            printf("%d ", high);
            low++;
            high--;
        }

        printf("\b \b");
    }
    
    else {
        printf("YES\n");
        
        printf("%d\n", n/2);
        for (int i=0; i < n/4; i++) {
            printf("%d ", low);
            printf("%d ", high);
            low++;
            high--;
        }

        printf("\n%d\n", n/2);
        for (int i=0; i < n/4; i++) {
            printf("%d ", low);
            printf("%d ", high);
            low++;
            high--;
        }

        printf("\b \b");
    }
    
}