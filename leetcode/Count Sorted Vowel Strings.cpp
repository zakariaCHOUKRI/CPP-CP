// LeetCode 1641 - Count Sorted Vowel Strings

#include <bits/stdc++.h>

using namespace std;

int countVowelStrings(int n) {

    int dp[55], li9bl;

    dp[1] = 5;
    dp[2] = 15;

    for (int i=3; i<=n; i++) {

        li9bl = dp[i-1];
        dp[i] = 0;

        for (int j=n-1; j>=1; j--) {

            dp[i] += li9bl;
            li9bl -= j*5;

        }


    }

    return dp[n];

}


int main(){

    printf("%d %d %d %d %d", countVowelStrings(1), countVowelStrings(2),
            countVowelStrings(3), countVowelStrings(4), countVowelStrings(33));

    return 0;
}