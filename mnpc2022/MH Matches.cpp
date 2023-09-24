#include <bits/stdc++.h>

using namespace std;

int main(){

    string str;
    int max, count, pos, maxPos;

    cin >> str;
    max = 0;
    maxPos = 0;

    for (pos=1; pos<str.size(); pos++) {
        // printf("pos%d\n", pos);
        count = 0;
        for(int i=pos; i<str.size(); i++) {
            // printf("str[i] = %c, str[i-pos] = %c\n", str[i], str[i-pos]);
            if (str[i] == str[i-pos]) {
                count++;
                if (count > max) {
                    max = count;
                    maxPos = pos;
                }
                
            }
        }
    }

    printf("%d %d", max, maxPos);

    return 0;
}