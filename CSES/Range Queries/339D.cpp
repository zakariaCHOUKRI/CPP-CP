#include <bits/stdc++.h>
using namespace std;

const int N=131073;
long long int arr[N];
struct segment{
    long long int value;
    long long int level;
}seg[4*N];
 
void build(int low,int high,int node) {

    if (low > high) {
        return;
    }

    if (low == high) {
        seg[node].value = arr[low];
        seg[node].level = 1;
        return;
    }

    int mid = (low + high)/2;
    build(low, mid, 2*node+1);
    build(mid+1, high, 2*node+2);
    seg[node].level=seg[2*node+1].level+1;

    if (seg[node].level&1) {
        seg[node].value = seg[2*node+1].value ^ seg[2*node+2].value;
    }
    else {
        seg[node].value = seg[2*node+1].value | seg[2*node+2].value;
    }
}
void update(int low,int high,int ind,long long int val,int node) {

    if (low > high) {
        return;
    }

    if (low == high) {
        seg[node].value=val;
    }

    else {
        int mid = (low+high)/2;
        
        if (low<=ind && ind<=mid) {
            update(low, mid, ind, val, 2*node+1);
        }
        else {
            update(mid+1, high, ind, val, 2*node+2);
        }

        if (seg[node].level&1) {
            seg[node].value=seg[2*node+1].value^seg[2*node+2].value;
        }
        else {
            seg[node].value=seg[2*node+1].value|seg[2*node+2].value;
        }
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
    long long int nn=pow(2, n);
 
    for(int i=0; i<nn; i++) {
        scanf("%lld", &arr[i]);
    }

    int p;
    long long int b;
    build(0, nn-1, 0);
    for(int i=0; i<m; i++) {
        cin >> p >> b;
        update(0, nn-1, p-1, b, 0);
        cout << seg[0].value << endl;
    }

    return 0;
}