// UVa 11456 - Trainsorting

#include <bits/stdc++.h>

using namespace std;

int lis(vector<int> arr, int n) {

    vector<int> lis;
    int n2 = n;
    while (n2--) lis.push_back(1);

    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i] > arr[j] && lis[i] <= lis[j]) lis[i] = lis[j] + 1;
        }
    }

    return *max_element(lis.begin(), lis.end());
}

int main() {

    int t, n, num;
    vector<int> arr;

    scanf("%d", &t);
    while(t--) {
        
        scanf("%d", &n);
    }


    return 0;
}