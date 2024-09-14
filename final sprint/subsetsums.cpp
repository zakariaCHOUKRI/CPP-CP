#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int n;

vector<long long> subsetSums() {

    vector<long long> res = {0};
         
    for (int i = 0; i <n; i++) {
        const int v = res.size();
        for (int t = 0; t < v; t++) {
            res.push_back(res[t] + arr[i]);
        }
    }

    return res;
}

int main() {

    n = 3;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    vector<long long> ss = subsetSums();

    for (auto elem: ss) {
        cout << elem << endl;
    }


    return 0;
}