#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main() {

    sor3a

    int n, arr[200100], count;

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    count = 1;
    for (int i=1; i<n; i++)
        if (arr[i] != arr[i-1])
            count++;

    cout << count;

    return 0;
}