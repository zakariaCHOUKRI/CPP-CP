#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
ll timer=0, a, b, s, n, x, q, op;
vector<ll> adj[200005];
ll enter[200005], quit[200005], value[200005];
vector<ll> aos(200005);
vector<ll> sg(4*200005);
 
void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        sg[v] = aos[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        sg[v] = sg[v*2] + sg[v*2+1];
    }
}
 
ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return sg[v];
    }
    ll tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
 
void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        sg[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        sg[v] = sg[v*2] + sg[v*2+1];
    }
}
 
 
void dfs(ll node, ll parent) {
    aos[timer] = value[node];
    enter[node] = timer++;
    for (ll neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node);
        }
    }
    quit[node] = timer-1;
}
 
int main () {
 
    cin >> n >> q;
    for (ll i=0; i<n; i++) {
        cin >> value[i];
    }
    for (ll i=0; i<n-1; i++) {
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
 
 
 
    dfs(0, -1);
    build(1, 0, n-1);
 
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> s >> x;
            s--;
            update(1,0,n-1,enter[s],x);
        } else {
            cin >> s;
            s--;
            cout << sum(1, 0, n-1, enter[s], quit[s]) << endl;
        }
 
    }
 
    return 0;
}
