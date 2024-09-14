#include<bits/stdc++.h>
using  namespace std;
typedef long long int ll;
 
const int sz = 1e5 +10;
const ll inf = 1e17 ;
 
vector<ll> adj[sz];
vector<ll> cont;
 
 
 
ll dp(ll idx){
    // cout << 'e';
    if(cont[idx] != -1) return cont[idx];
    
    if(adj[idx].size() == 0){
        cont[idx] = 1;
        return cont[idx];
    }
    
    int ans = 0;
    
    for(auto x : adj[idx]){
        ans += dp(x);
    }
    
    cont[idx] = ans;
    return ans;
}
 
void solve(){
    
    ll n;
    cin >> n;
    
    for(int i = 0; i < n; i++) adj[i].clear();
    cont.clear();
    vector<ll> w;
    w.resize(n);
    
    
    cont.resize(n, -1);
    
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    
    ll a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        a--; 
        b--;
        adj[a].push_back(b);
        // adj[b].push_back(a);
        // cout << "r";
    }
    
    
    
    dp(0);
    
    //for(int i = 0; i < n; i++) cout << cont[i] << " ";
    
    ll pre = 0;
    ll mn = inf;
    
    
    
    for(int i = 0; i < n; i++){
        mn = min(mn, w[i] * cont[i]);
        pre += w[i] * cont[i];
    }
    if(mn < 0){
        cout << pre - mn << "\n";
    }else {
        cout << pre << "\n";
    }
    
    
}
 
 
 
 
int main(){
    //cout << "e";
    
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}