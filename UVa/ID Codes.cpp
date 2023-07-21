// UVa 146 - ID Codes

#include <bits/stdc++.h>

using namespace std;

int main() {

    string input;

    while (true) {
        
        getline(cin, input);
        if (input[0] == '#') break;
        
        if (next_permutation(input.begin(), input.end())) printf("%s\n", input.c_str());
        else printf("No Successor\n");


    }





return 0;
}