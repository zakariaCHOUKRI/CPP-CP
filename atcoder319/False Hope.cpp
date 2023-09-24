#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int ts3odFactoriel = 9*8*7*6*5*4*3*2;

bool check (int i, int j) {
    if (i == 0)
        if (j==1 || j==3 || j==4)
            return true;

    if (i == 1)
        if (j==4 || j==0 || j==2)
            return true;

    if (i == 2)
        if (j==1 || j==4 || j==5)
            return true;
    
    if (i == 3)
        if (j==0 || j==6 || j==4)
            return true;

    if (i == 4)
        if (j==0 || j==1 || j==2 || j==3 || j==5 || j==6 || j==7 || j==8)
            return true;

    if (i == 5)
        if (j==2 || j==8 || j==4)
            return true;

    if (i == 6)
        if (j==3 || j==4 || j==7)
            return true;

    if (i == 7)
        if (j==8 || j==6 || j==4)
            return true;

    if (i == 8)
        if (j==5 || j==4 || j==7)
            return true;

    if (j == 0)
        if (i==1 || i==3 || i==4)
            return true;

    if (j == 1)
        if (i==4 || i==0 || i==2)
            return true;

    if (j == 2)
        if (i==1 || i==4 || i==5)
            return true;
    
    if (j == 3)
        if (i==0 || i==6 || i==4)
            return true;

    if (j == 4)
        if (i==0 || i==1 || i==2 || i==3 || i==5 || i==6 || i==7 || i==8)
            return true;

    if (j == 5)
        if (i==2 || i==8 || i==4)
            return true;

    if (j == 6)
        if (i==3 || i==7 || i==7)
            return true;

    if (j == 7)
        if (i==8 || i==6 || i==4)
            return true;

    if (j == 8)
        if (i==5 || i==7 || i==4)
            return true;

    return false;
}

int main() {

    sor3a

    int m[9], permutations[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int count = 0;

    for (int i=0; i<9; i++)
        cin >> m[i];

    for (int i=0; i<ts3odFactoriel; i++) {
        for (int j=0; j<8; j++) {
            if (m[permutations[j]] == m[permutations[j+1]] && check(permutations[j], permutations[j+1])) {
                count++;
                break;
            }
        }
        next_permutation(permutations, permutations + 9);
    }

    // for (int i=0; i<9; i++)
    //     cout << m[i] << " ";
    // cout << "\n";

    float result = ((float) count) / ((float) ts3odFactoriel);
    // cout << count << " " << ts3odFactoriel << "\n";
    cout << 1 - result;

    return 0;
}