#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    pair<long long, long long> arr[1005];

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }
    arr[n] = arr[0];


    long long res = 0;
    for (int i=0; i<n; i++) {
        res += arr[i].first*arr[i+1].second - arr[i+1].first*arr[i].second;
    }

    cout << abs(res);

    return 0;
}