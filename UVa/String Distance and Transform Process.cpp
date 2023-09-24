// UVa 526 - String Distance and Transform Process

#include <bits/stdc++.h>

using namespace std;

// dp[i][j] will hold the Levenshtein distance between
// the first i characters of s and the first j characters of t
int dp[90][90], offset, steps;
string a, b;

int LevenshteinDistance(string s, string t) {

    int m, n, substitutionCost;

    m = s.length();
    n = t.length();

    // Initialize the matrix
    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;
    
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
            substitutionCost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            
            dp[i][j] = min({dp[i - 1][j] + 1,         // deletion
                                dp[i][j - 1] + 1,         // insertion
                                dp[i - 1][j - 1] + substitutionCost}); // substitution
        }
    }
    
    return dp[m][n];
}

void print(int i, int j){
    if(i==0 && j==0) return;
    else if(i!=0 && j!=0 && a[i-1] == b[j-1]){
        print(i-1,j-1);
    } else if(j!=0 && dp[i][j] == dp[i][j-1]+1){
        print(i,j-1);
        offset++;
        printf("%d Insert %d,%c\n",++steps,i+offset,b[j-1]);
    } else if(i!=0 && dp[i][j] == dp[i-1][j]+1){
        print(i-1,j);
        printf("%d Delete %d\n",++steps,i+offset);
        offset--;
    } else if(dp[i][j] == dp[i-1][j-1]+1){
        print(i-1,j-1);
        printf("%d Replace %d,%c\n",++steps,i+offset,b[j-1]);
    }
}

int main(){

    bool printed = false;

    while (getline(cin, a), getline(cin, b)) {

        if(printed) printf("\n");
        printed = true;
        printf("%d\n", LevenshteinDistance(a, b));

        offset = steps = 0;
        print(a.length(),b.length());
    }

    return 0;
}