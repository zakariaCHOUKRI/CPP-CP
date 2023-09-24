// LeetCode 1791 - Find Center of Star Graph

#include <bits/stdc++.h>

using namespace std;


int findCenter(vector<vector<int>>& edges) {
    set<int> s;

    for (vector<int> i: edges) {
        for (int j: i) {
            if (s.count(j) == 0) s.insert(j);
            else return j;
        }
    }
}

int main(){

    vector<vector<int>> edges = {{1,2},{2,3},{4,2}};
    printf("Mdfqdsfqsd\n");
    printf("%d", findCenter(edges));

    return 0;
}